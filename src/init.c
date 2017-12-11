#include <postgres.h>
#include <pg_config.h>
#include <access/xact.h>
#include <commands/extension.h>
#include <miscadmin.h>
#include <utils/guc.h>

#include "executor.h"
#include "extension.h"
#include "guc.h"
#include "catalog.h"

#ifdef PG_MODULE_MAGIC
PG_MODULE_MAGIC;
#endif


extern void _chunk_dispatch_info_init(void);
extern void _chunk_dispatch_info_fini(void);

extern void _hypertable_cache_init(void);
extern void _hypertable_cache_fini(void);

extern void _cache_invalidate_init(void);
extern void _cache_invalidate_fini(void);

extern void _cache_init(void);
extern void _cache_fini(void);

extern void _planner_init(void);
extern void _planner_fini(void);

extern void _process_utility_init(void);
extern void _process_utility_fini(void);

extern void _event_trigger_init(void);
extern void _event_trigger_fini(void);

extern void _parse_analyze_init(void);
extern void _parse_analyze_fini(void);

extern void PGDLLEXPORT _PG_init(void);
extern void PGDLLEXPORT _PG_fini(void);

void
_PG_init(void)
{
	_chunk_dispatch_info_init();
	_cache_init();
	_hypertable_cache_init();
	_cache_invalidate_init();
	_planner_init();
	_executor_init();
	_event_trigger_init();
	_process_utility_init();
	_parse_analyze_init();
	_guc_init();
}

void
_PG_fini(void)
{
	/*
	 * Order of items should be strict reverse order of _PG_init. Please
	 * document any exceptions.
	 */
	_guc_fini();
	_parse_analyze_fini();
	_process_utility_fini();
	_event_trigger_fini();
	_executor_fini();
	_planner_fini();
	_cache_invalidate_fini();
	_hypertable_cache_fini();
	_cache_fini();
	_chunk_dispatch_info_fini();
}
