/* Copyright (C) 2000 MySQL AB & MySQL Finland AB & TCX DataKonsult AB
   
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA */


extern const char	*unknown_sqlstate;

#ifdef	__cplusplus
extern "C" {
#endif

ulong STDCALL net_field_length(uchar **packet);
my_ulonglong net_field_length_ll(uchar **packet);

MYSQL_FIELD *unpack_fields(MYSQL_DATA *data,MEM_ROOT *alloc,uint fields,
			   my_bool default_value, uint server_capabilities);
my_bool advanced_command(MYSQL *mysql, enum enum_server_command command,
			 const char *header, ulong header_length,
			 const char *arg, ulong arg_length, my_bool skip_check);
void free_rows(MYSQL_DATA *cur);
MYSQL_DATA *read_rows (MYSQL *mysql,MYSQL_FIELD *fields,
		       uint field_count);
my_bool mysql_autenticate(MYSQL *mysql, const char *passwd);
void fetch_lengths(ulong *to, MYSQL_ROW column, uint field_count);
void free_old_query(MYSQL *mysql);
void end_server(MYSQL *mysql);
my_bool mysql_reconnect(MYSQL *mysql);
#ifdef	__cplusplus
}
#endif

#ifdef MYSQL_SERVER
#define protocol_41(A) FALSE
#else
#define protocol_41(A) ((A)->server_capabilities & CLIENT_PROTOCOL_41)
#endif

