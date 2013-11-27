/*
 * states.h - save-state variable class definitions
 *
 * Copyright (C) 2004 Stefan Jahn <stefan@lkcc.org>
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this package; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor,
 * Boston, MA 02110-1301, USA.  
 *
 * $Id$
 *
 */

#ifndef __STATES_H__
#define __STATES_H__

template <class state_type_t>
class states
{
 public:
  // constructor and destructor set
  states ();
  states (const states &);
  ~states ();

  // save-state variables for transient analysis
  state_type_t getState (int, int n = 0);
  void setState (int, state_type_t, int n = 0);
  void initStates (void);
  void clearStates (void);
  int  getStates (void) { return nstates; }
  void setStates (int n) { nstates = n; }
  void nextState (void);
  void prevState (void);
  void fillState (int, state_type_t);
  void saveState (int, state_type_t *);

 private:
  state_type_t * stateval;
  int nstates;
  int currentstate;
};

#include "states.cpp"

#endif /* __STATES_H__ */
