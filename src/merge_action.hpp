/*
 * ====================================================================
 * Copyright (c) 2002 The RapidSvn Group.  All rights reserved.
 *
 * This software is licensed as described in the file LICENSE.txt,
 * which you should have received as part of this distribution.
 *
 * This software consists of voluntary contributions made by many
 * individuals.  For exact contribution history, see the revision
 * history and logs, available at http://rapidsvn.tigris.org/.
 * ====================================================================
 */
#ifndef _MERGE_ACTION_H_INCLUDED_
#define _MERGE_ACTION_H_INCLUDED_

#include "action_thread.hpp"
#include "merge_dlg.hpp"

class MergeAction:public ActionThread
{
private:
  MergeDlg::sData m_data;
  wxFrame *m_pFrame;

  /**
   * Gets the revision from a string.
   */
  long getRevision (wxString & str);

public:
   MergeAction (wxFrame * frame, Tracer * tr);

  void Perform ();
  void *Entry ();
};

#endif

/* -----------------------------------------------------------------
 * local variables:
 * eval: (load-file "../rapidsvn-dev.el")
 * end:
 */