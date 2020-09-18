
/* auto-generated by gen_syscalls.py, don't edit */
#ifndef Z_INCLUDE_SYSCALLS_PS2_H
#define Z_INCLUDE_SYSCALLS_PS2_H


#ifndef _ASMLANGUAGE

#include <syscall_list.h>
#include <syscall.h>

#if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6)
#pragma GCC diagnostic push
#endif

#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif

#ifdef __cplusplus
extern "C" {
#endif

extern int z_impl_ps2_config(struct device * dev, ps2_callback_t callback_isr);
static inline int ps2_config(struct device * dev, ps2_callback_t callback_isr)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		return (int) arch_syscall_invoke2(*(uintptr_t *)&dev, *(uintptr_t *)&callback_isr, K_SYSCALL_PS2_CONFIG);
	}
#endif
	compiler_barrier();
	return z_impl_ps2_config(dev, callback_isr);
}


extern int z_impl_ps2_write(struct device * dev, uint8_t value);
static inline int ps2_write(struct device * dev, uint8_t value)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		return (int) arch_syscall_invoke2(*(uintptr_t *)&dev, *(uintptr_t *)&value, K_SYSCALL_PS2_WRITE);
	}
#endif
	compiler_barrier();
	return z_impl_ps2_write(dev, value);
}


extern int z_impl_ps2_read(struct device * dev, uint8_t * value);
static inline int ps2_read(struct device * dev, uint8_t * value)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		return (int) arch_syscall_invoke2(*(uintptr_t *)&dev, *(uintptr_t *)&value, K_SYSCALL_PS2_READ);
	}
#endif
	compiler_barrier();
	return z_impl_ps2_read(dev, value);
}


extern int z_impl_ps2_enable_callback(struct device * dev);
static inline int ps2_enable_callback(struct device * dev)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		return (int) arch_syscall_invoke1(*(uintptr_t *)&dev, K_SYSCALL_PS2_ENABLE_CALLBACK);
	}
#endif
	compiler_barrier();
	return z_impl_ps2_enable_callback(dev);
}


extern int z_impl_ps2_disable_callback(struct device * dev);
static inline int ps2_disable_callback(struct device * dev)
{
#ifdef CONFIG_USERSPACE
	if (z_syscall_trap()) {
		return (int) arch_syscall_invoke1(*(uintptr_t *)&dev, K_SYSCALL_PS2_DISABLE_CALLBACK);
	}
#endif
	compiler_barrier();
	return z_impl_ps2_disable_callback(dev);
}


#ifdef __cplusplus
}
#endif

#if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6)
#pragma GCC diagnostic pop
#endif

#endif
#endif /* include guard */