/*
 * ====================================================================
 * Copyright (c) 2000 The Apache Software Foundation.  All rights
 * reserved.
 *
 * This software is licensed as described in the file LICENSE.txt,
 * which you should have received as part of this distribution.
 *
 * This software consists of voluntary contributions made by many
 * individuals.  For exact contribution history, see the revision
 * history and logs, available at http://rapidsvn.tigris.org/.
 * ====================================================================
 */
#include "include.h"
#include "exceptions.h"

RapidSvnEx::RapidSvnEx (const wxString & __estr, const long __code)
{
  code = __code;
  what (__estr);
}

RapidSvnEx::~RapidSvnEx ()
{
}

RapidSvnEx & RapidSvnEx::operator = (const RapidSvnEx & rhs)
{
  if (this == &rhs)
    return *this;

  estr = rhs.estr;
  code = rhs.code;

  return *this;
}

void
RapidSvnEx::what (const wxString & __what)
{
  estr.Printf (_T ("%s  code: %ld"), __what.c_str (), code);
}
/* -----------------------------------------------------------------
 * local variables:
 * eval: (load-file "../rapidsvn-dev.el")
 * end:
 */