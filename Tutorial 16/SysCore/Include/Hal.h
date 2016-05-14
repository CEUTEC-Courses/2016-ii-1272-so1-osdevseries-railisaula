#ifndef _HAL_H
#define _HAL_H
//****************************************************************************
//**
//**    Hal.h
//**		Hardware Abstraction Layer Interface
//**
//**	The Hardware Abstraction Layer (HAL) provides an abstract interface
//**	to control the basic motherboard hardware devices. This is accomplished
//**	by abstracting hardware dependencies behind this interface.
//**
//**	All routines and types are declared extern and must be defined within
//**	external libraries to define specific hal implimentations.
//**
//****************************************************************************

#ifndef ARCH_X86
#pragma error "HAL not implimented for this platform"
#endif

//============================================================================
//    INTERFACE REQUIRED HEADERS
//============================================================================

#include <stdint.h>

//============================================================================
//    INTERFACE DEFINITIONS / ENUMERATIONS / SIMPLE TYPEDEFS
//============================================================================

#define far
#define near

//============================================================================
//    INTERFACE CLASS PROTOTYPES / EXTERNAL CLASS REFERENCES
//============================================================================
//============================================================================
//    INTERFACE STRUCTURES / UTILITY CLASSES
//============================================================================
//============================================================================
//    INTERFACE DATA DECLARATIONS
//============================================================================
//============================================================================
//    INTERFACE FUNCTION PROTOTYPES
//============================================================================

//! initialize hardware abstraction layer
extern	int				_cdecl	hal_initialize ();

//! shutdown hardware abstraction layer
extern	int				_cdecl	hal_shutdown ();

//! generates interrupt
extern	void			_cdecl	geninterrupt (int n);

//! notifies hal interrupt is done
extern	void			_cdecl	interruptdone (unsigned int intno);

//! output sound to speaker
extern	void			_cdecl	sound (unsigned frequency);

//! read byte from device using port mapped io
extern	unsigned char	_cdecl inportb (unsigned short portid);

//! write byte to device through port mapped io
extern void				_cdecl outportb (unsigned short portid, unsigned char value);

//! enables all hardware interrupts
extern void				_cdecl enable ();

//! disable all hardware interrupts
extern void				_cdecl disable ();

//! sets new interrupt vector
extern void				_cdecl setvect (int intno, void (_cdecl far &vect) ( ) );

//! returns current interrupt vector
extern void				(_cdecl far * _cdecl	getvect (int intno)) ( );

//! returns cpu vender
extern const char*		_cdecl get_cpu_vender ();

//! returns current tick count (only for demo)
extern int				_cdecl get_tick_count ();

//============================================================================
//    INTERFACE OBJECT CLASS DEFINITIONS
//============================================================================
//============================================================================
//    INTERFACE TRAILING HEADERS
//============================================================================
//****************************************************************************
//**
//**    END [Hal.h]
//**
//****************************************************************************
#endif
