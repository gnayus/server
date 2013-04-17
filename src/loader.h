#ifndef TOKU_LOADER_H
#define TOKU_LOADER_H

#if defined(__cplusplus)
extern "C" {
#endif

/* Copyright (c) 2007-2010 Tokutek Inc.  All rights reserved.
 *
 * The technology is licensed by the Massachusetts Institute of Technology, 
 * Rutgers State University of New Jersey, and the Research Foundation of 
 * State University of New York at Stony Brook under United States of America 
 * Serial No. 11/760379 and to the patents and/or patent applications resulting from it.
 */

int toku_loader_create_loader(DB_ENV *env, DB_TXN *txn, DB_LOADER **blp, DB *src_db, int N, DB *dbs[N], uint32_t db_flags[N], uint32_t dbt_flags[N], uint32_t loader_flags);

int toku_loader_set_error_callback(DB_LOADER *loader, void (*error_cb)(DB *db, int i, int err, DBT *key, DBT *val, void *error_extra), void *error_extra);

int toku_loader_set_poll_function(DB_LOADER *loader, int (*poll_func)(void *poll_extra, float progress), void *poll_extra);

int toku_loader_put(DB_LOADER *loader, DBT *key, DBT *val);

int toku_loader_close(DB_LOADER *loader);

int toku_loader_abort(DB_LOADER *loader);

// Remove any loader temp files that may have been left from a crashed system
int toku_loader_cleanup_temp_files(DB_ENV *env);

#if defined(__cplusplus)
}
#endif

#endif
