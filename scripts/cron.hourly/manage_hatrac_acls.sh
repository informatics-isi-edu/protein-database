#!/bin/bash

su -c "psql -q -d hatrac" - hatrac <<EOF
-- remove ownership of user-id and give read/write access based on uid
UPDATE hatrac.name n
SET "create" = ARRAY['https://auth.globus.org/'||(regexp_split_to_array(name, '/'))[ cardinality(regexp_split_to_array(name, '/')) ]],
  "subtree-create" = ARRAY['https://auth.globus.org/'||(regexp_split_to_array(name, '/'))[ cardinality(regexp_split_to_array(name, '/')) ]],
  "subtree-update" = ARRAY['https://auth.globus.org/'||(regexp_split_to_array(name, '/'))[ cardinality(regexp_split_to_array(name, '/')) ]],
  "subtree-read" = ARRAY['https://auth.globus.org/'||(regexp_split_to_array(name, '/'))[ cardinality(regexp_split_to_array(name, '/')) ]],
  "owner" = NULL,
  "subtree-owner" = NULL
WHERE ( name ~ '^(/dev)?/pdb/submitted/uid/[^/]+$'
     OR name ~ '/dev/pdb/user/[^/]+$')
  AND "owner" IS NOT NULL
  AND "owner"::text != '{}'
;  

-- remove ownership of all namespace and object except root
UPDATE hatrac.name n
set "read" = owner, owner = NULL, "subtree-owner" = NULL
WHERE NOT n.name ~ '^(/|/dev)$'
  AND id != 1
  AND "read" IS NULL
  AND "owner" IS NOT NULL;

-- remove ownership of all versions so they can't be deleted.
UPDATE hatrac.version n
SET "read" = owner, owner = NULL
WHERE "read" IS NULL
  AND "owner" IS NOT NULL;

EOF


