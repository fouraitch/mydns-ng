/**************************************************************************************************
	$Id: util.c,v 1.25 2005/04/20 16:49:12 bboy Exp $

	util.c: Routines shared by the utility programs.

	Copyright (C) 2002-2005  Don Moore <bboy@bboy.net>

	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	(at Your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
**************************************************************************************************/

#include "util.h"

CONF *Conf;															/* Configuration data */


/**************************************************************************************************
	DB_CONNECT
	Connect to the database.
**************************************************************************************************/
void
db_connect(void)
{
	char *user = conf_get(&Conf, "db-user", NULL);
	char *host = conf_get(&Conf, "db-host", NULL);
	char *database = conf_get(&Conf, "database", NULL);
	char *password = conf_get(&Conf, "db-password", NULL);

	/* If db- vars aren't present, try mysql- for backwards compatibility */
	if (!user) user = conf_get(&Conf, "mysql-user", NULL);
	if (!host) host = conf_get(&Conf, "mysql-host", NULL);
	if (!password) password = conf_get(&Conf, "mysql-password", NULL);
	if (!password) password = conf_get(&Conf, "mysql-pass", NULL);

	sql_open(user, password, host, database);
	Verbose(_("connected to %s, database \"%s\""), host, database);
}
/*--- db_connect() ------------------------------------------------------------------------------*/

/* vi:set ts=3: */
/* NEED_PO */
