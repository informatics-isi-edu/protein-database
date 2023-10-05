// Configure deployment-specific data here

var chaiseConfig = {
		disableExternalLinkModal: true,
		internaleHosts: ["github.com"],
	    confirmDelete: true,
            signUpURL: 'https://app.globus.org/groups/99da042e-64a6-11ea-ad5f-0ef992ed7ca1/about',
	    navbarBrandText: 'PDB-Dev',
	    authnProvider: 'goauth',
	    feedbackURL: 'http://goo.gl/forms/f30sfheh4H',
	    helpURL: '/help/using-the-data-browser/',
	    showBadgeCounts: false,
	    layout: 'table',
	    maxColumns: 10,
	    customCSS: '/assets/css/chaise.css',
	    navbarBrand: '/',
	    headTitle: 'PDB-Dev',
	    defaultCatalog: 99,
	    recordUiGridEnabled: false,
	    recordUiGridExportCSVEnabled: true,
	    recordUiGridExportPDFEnabled: true,
	    showUnfilteredResults: true,
	    showDeleteButton: true,
	    deleteRecord: true,
	    editRecord: true,
	    plotViewEnabled: true,
	    showFaceting: true,
	    showExportButton: true,
            resolverImplicitCatalog: 99,
	    maxRecordsetRowHeight: 235
};
