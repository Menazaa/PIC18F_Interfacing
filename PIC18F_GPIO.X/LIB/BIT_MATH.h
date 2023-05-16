/* 
 * File:   BIT_MATH.h
 * Author: Moahmed Menazaa
 *
 * Created on May 16, 2023, 12:47 PM
 */

#ifndef BIT_MATH_H
#define	BIT_MATH_H

/* Section : Macros Declarations */
#define MASK    1

/* Section : Macros Functions Declarations */
#define SET_BIT(VAR,BIT)    (VAR |=(MASK<<BIT))
#define CLR_BIT(VAR,BIT)    (VAR &= (~(MASK<<BIT)))
#define GET_BIT(VAR,BIT)    ((VAR>>BIT) & MASK)
#define TOG_BIT(VAR,BIT)    (VAR ^=(MASK<<BIT))

#endif	/* BIT_MATH_H */

