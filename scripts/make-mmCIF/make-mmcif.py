#!/usr/bin/env python3

import ihm.dumper
import ihm.model
import ihm.protocol
import Bio.PDB
import sys
import itertools

def get_input_parser(fname):
    if fname.endswith('.cif'):
        return Bio.PDB.MMCIFParser()
    else:
        return Bio.PDB.PDBParser()


class AllPDBModels(object):
    """Pass all BioPython models through to IHM"""
    def __init__(self, file_name, asym_units, chem_comps, **kwargs):
        self.kwargs = kwargs
        self.file_name = file_name
        self.asym_units = asym_units
        self.chem_comps = chem_comps

    def get_models(self):
        # Use BioPython to read the structure from a PDB file, and yield
        # a PDBModel for each model in the file
        p = get_input_parser(self.file_name)
        s = p.get_structure('rep', self.file_name)
        for model in s:
            yield PDBModel(bp_model=model, asym_units=self.asym_units,
                           chem_comps=self.chem_comps, **self.kwargs)


class PDBModel(ihm.model.Model):
    """Pass a BioPython model through to IHM"""
    def __init__(self, bp_model, asym_units, chem_comps, **kwargs):
        super(PDBModel, self).__init__(**kwargs)
        self.bp_model = bp_model
        self.asym_units = asym_units
        self.chem_comps = chem_comps

    def get_atoms(self):
        # Yield a set of ihm.model.Atom objects for a BioPython model
        for nchain, chain in enumerate(self.bp_model):
            asym = self.asym_units[nchain]
            nres = 1
            for residue in chain:
                # Skip unknown residues, non-polymers
                if residue.resname not in self.chem_comps:
                    continue
                for atom in residue:
                    coord = atom.get_vector()
                    yield ihm.model.Atom(asym_unit=asym, seq_id=nres,
                            atom_id=atom.get_id(), x=coord[0], y=coord[1],
                            z=coord[2], type_symbol=atom.element)
                nres += 1


def get_sequence(fname, chem_comps):
    """Get the primary sequence as a set of ihm.ChemComp objects"""
    p = get_input_parser(fname)
    s = p.get_structure('rep', fname)
    seqs = []
    chains = []
    model0 = next(s.get_models())
    for chain in model0.get_chains():
        chains.append(chain.id)
        seq = []
        for r in chain.get_residues():
            # Skip unknown residues, non-polymers
            if r.resname not in chem_comps:
                continue
            seq.append(chem_comps[r.resname])
        seqs.append(seq)
    return seqs, chains

def get_chem_comps():
    """Get all possible chemical components to include in the output"""
    chem_comps = {}
    for comp in itertools.chain(ihm.LPeptideAlphabet._comps.values(),
                                ihm.RNAAlphabet._comps.values(),
                                ihm.DNAAlphabet._comps.values()):
        chem_comps[comp.id] = comp
    return chem_comps

if len(sys.argv) != 2:
    print("Usage: %s input.pdb" % sys.argv[0], file=sys.stderr)
    sys.exit(1)
fname = sys.argv[1]
chem_comps = get_chem_comps()

seqs, chains = get_sequence(fname, chem_comps)

system = ihm.System(title='Auto-generated system')

# Make asym units for each chain and entities for all unique sequences
seen_seqs = {}
for seq, chain in zip(seqs, chains):
    tupseq = tuple(seq)
    if tupseq in seen_seqs:
        entity = seen_seqs[tupseq]
    else:
        entity = ihm.Entity(seq)
        system.entities.append(entity)
        seen_seqs[tupseq] = entity
    asym = ihm.AsymUnit(entity, id=chain)
    system.asym_units.append(asym)

# Simple assembly containing all chains
assembly = ihm.Assembly(system.asym_units, name='Modeled assembly')

# Simple atomic representation for everything
rep = ihm.representation.Representation(
        [ihm.representation.AtomicSegment(asym, rigid=False)
         for asym in system.asym_units])

# Simple modeling protocol
protocol = ihm.protocol.Protocol(name='modeling')

# Single state in a single state group, containing all models in the file
allm = AllPDBModels(assembly=assembly, representation=rep, file_name=fname,
                    asym_units=system.asym_units, chem_comps=chem_comps,
                    protocol=protocol)
s = ihm.model.State([ihm.model.ModelGroup(allm.get_models())])
sg = ihm.model.StateGroup([s])
system.state_groups.append(sg)

# Write out an mmCIF file
with open('output.cif', 'w') as fh:
    ihm.dumper.write(fh, [system])
