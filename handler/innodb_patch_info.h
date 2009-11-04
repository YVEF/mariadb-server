/* Copyright (C) 2002-2006 MySQL AB
  
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; version 2 of the License.
  
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA */

#ifdef USE_PRAGMA_INTERFACE
#pragma interface                      /* gcc class implementation */
#endif

struct innodb_enhancement {
       const char *file;
       const char *name;
       const char *comment;
       const char *link;
}innodb_enhancements[] = {
{"xtradb_show_enhancements","I_S.XTRADB_ENHANCEMENTS","","http://www.percona.com/docs/wiki/percona-xtradb"},
{"innodb_show_status","Improvements to SHOW INNODB STATUS","Memory information and lock info fixes","http://www.percona.com/docs/wiki/percona-xtradb"},
{"innodb_io","Improvements to InnoDB IO","","http://www.percona.com/docs/wiki/percona-xtradb"},
{"innodb_opt_lru_count","Fix of buffer_pool mutex","Decreases contention on buffer_pool mutex on LRU operations","http://www.percona.com/docs/wiki/percona-xtradb"},
{"innodb_buffer_pool_pages","Information of buffer pool content","","http://www.percona.com/docs/wiki/percona-xtradb"},
{"innodb_expand_undo_slots","expandable maximum number of undo slots","from 1024 (default) to about 4000","http://www.percona.com/docs/wiki/percona-xtradb"},
{"innodb_extra_rseg","allow to create extra rollback segments","When create new db, the new parameter allows to create more rollback segments","http://www.percona.com/docs/wiki/percona-xtradb"},
{"innodb_overwrite_relay_log_info","overwrite relay-log.info when slave recovery","Building as plugin, it is not used.","http://www.percona.com/docs/wiki/percona-xtradb:innodb_overwrite_relay_log_info"},
{"innodb_thread_concurrency_timer_based","use InnoDB timer based concurrency throttling (backport from MySQL 5.4.0)","",""},
{"innodb_expand_import","convert .ibd file automatically when import tablespace","the files are generated by xtrabackup export mode.","http://www.percona.com/docs/wiki/percona-xtradb"},
{"innodb_dict_size_limit","Limit dictionary cache size","Variable innodb_dict_size_limit in bytes","http://www.percona.com/docs/wiki/percona-xtradb"},
{"innodb_split_buf_pool_mutex","More fix of buffer_pool mutex","Spliting buf_pool_mutex and optimizing based on innodb_opt_lru_count","http://www.percona.com/docs/wiki/percona-xtradb"},
{"innodb_stats","Additional features about InnoDB statistics/optimizer","","http://www.percona.com/docs/wiki/percona-xtradb"},
{"innodb_recovery_patches","Bugfixes and adjustments about recovery process","","http://www.percona.com/docs/wiki/percona-xtradb"},
{"innodb_purge_thread","Enable to use purge devoted thread","","http://www.percona.com/docs/wiki/percona-xtradb"},
{"innodb_admin_command_base","XtraDB specific command interface through i_s","","http://www.percona.com/docs/wiki/percona-xtradb"},
{"innodb_show_lock_name","Show mutex/lock name instead of crated file/line","","http://www.percona.com/docs/wiki/percona-xtradb"},
{"innodb_extend_slow","Extended statistics in slow.log","It is InnoDB-part only. It needs to patch also to mysqld.","http://www.percona.com/docs/wiki/percona-xtradb"},
{NULL, NULL, NULL, NULL}
};
