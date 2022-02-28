/**
 * \file
 */

#include <config.h>

#if defined(HOST_SERENITY)

#include <mono/utils/mono-threads.h>
#include <unistd.h>
#include <serenity.h>

void
mono_threads_platform_get_stack_bounds (guint8 **staddr, size_t *stsize)
{
    if (get_stack_bounds((uintptr_t*)staddr, stsize) < 0) {
        g_error ("%s: get_stack_bounds failed", __func__);
    }
}

guint64
mono_native_thread_os_id_get (void)
{
	return gettid();
}

#else

#include <mono/utils/mono-compiler.h>

MONO_EMPTY_SOURCE_FILE (mono_threads_linux);

#endif
