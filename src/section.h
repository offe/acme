// ACME - a crossassembler for producing 6502/65c02/65816/65ce02 code.
// Copyright (C) 1998-2016 Marco Baye
// Have a look at "acme.c" for further info
//
// section stuff
#ifndef section_H
#define section_H


#include "config.h"


// "section" structure type definition
struct section {
	scope_t		scope;	// section's scope
	const char	*type;	// "Zone", "Subzone" or "Macro"
	char		*title;	// zone title, subzone title or macro title
	int		allocated;	// whether title was malloc()'d
};


// current section structure
extern struct section	*section_now;


// write given info into given structure and activate it
extern void section_new(struct section *section, const char *type, char *title, int allocated);
// setup outermost section
extern void section_passinit(void);
// tidy up: if necessary, release section title.
extern void section_finalize(struct section *section);


#endif
