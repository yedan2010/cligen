/*
  Copyright (C) 2001-2016 Olof Hagsand

  This file is part of CLIgen.

  CLIgen is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  CLIgen is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with CLIgen; see the file COPYING.
*/

#ifndef _CLIGEN_SYNTAX_H_
#define _CLIGEN_SYNTAX_H_

/*
 * Types
 */
typedef void *(str2fn_mapper)(char *str, void *arg, char **err);

/*
 * Prototypes
 */
int
cligen_parse_str(cligen_handle  h,
		 char          *str,
		 char          *name, 
		 parse_tree    *pt,
		 cvec          *globals);
int
cligen_parse_file(cligen_handle h,
		  FILE         *f,
		  char         *name, 
		  parse_tree   *obsolete,
		  cvec         *globals);

int cligen_parse_line(cligen_handle h,
               int           linenum,
	       cg_obj       *co_top, 
	       char         *filename, 
	       char         *string,
	       char         *callback_str,
	       cg_fnstype_t *callback,
	       cg_var       *arg,
	       int           hide);

int cligen_str2fn(parse_tree pt, 
		  str2fn_mapper *str2fn1, void *fnarg1, 
		  str2fn_mapper *str2fn2, void *fnarg2);
int cligen_callback_str2fn(parse_tree, cg_str2fn_t *str2fn, void *fnarg);
int cligen_parse_debug(int d); 

#endif /* _CLIGEN_SYNTAX_H_ */

