/*
 * ====================================================================
 * Copyright (c) 2002-2006 The RapidSvn Group.  All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program (in the file GPL.txt); if not, write to 
 * the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, 
 * Boston, MA  02110-1301  USA
 *
 * This software consists of voluntary contributions made by many
 * individuals.  For exact contribution history, see the revision
 * history and logs, available at http://rapidsvn.tigris.org/.
 * ====================================================================
 */

// app
#include "test_path.hpp"
#include <string>

//svncpp
#include "svncpp/path.hpp"

CPPUNIT_TEST_SUITE_REGISTRATION (PathTestCase);

void
PathTestCase::setUp ()
{
}

void
PathTestCase::testInit ()
{
  svn::Path pathEmpty;
  CPPUNIT_ASSERT (strcmp ("", pathEmpty.c_str ()) == 0);
  CPPUNIT_ASSERT (pathEmpty.isset () == false);

  svn::Path pathOne = "/some/path/to/repository";
  CPPUNIT_ASSERT (strcmp ("/some/path/to/repository", pathOne.c_str ()) == 0);
  CPPUNIT_ASSERT (pathOne.isset ());

  svn::Path pathTwo = "http://this.is/a/url";
  CPPUNIT_ASSERT (strcmp ("http://this.is/a/url", pathTwo.c_str ()) == 0);
  CPPUNIT_ASSERT (pathTwo.isset ());

  svn::Path pathThree = "file:///this.is/a/url";
  CPPUNIT_ASSERT (strcmp ("file:///this.is/a/url", pathThree.c_str ()) == 0);
  CPPUNIT_ASSERT (pathThree.isset ());
}

void
PathTestCase::testSplit ()
{
  svn::Path pathTest = "/some/path/to/repository";
  std::string dirpath = "";
  std::string basename = "";

  pathTest.split (dirpath, basename);
  CPPUNIT_ASSERT (dirpath == "/some/path/to");
  CPPUNIT_ASSERT (basename == "repository");

  svn::Path test1 = "file.txt";
  std::string dir, file, ext;

  test1.split (dir, file, ext);
  CPPUNIT_ASSERT (strcmp (file.c_str (), "file") == 0);  
  CPPUNIT_ASSERT (strcmp (dir.c_str (), "") == 0);  
  CPPUNIT_ASSERT (strcmp (ext.c_str (), ".txt") == 0);
}

void
PathTestCase::testAddComponent ()
{
  svn::Path pathTest = "/some/path/to/repository";
  std::string newBasename = "newname";

  pathTest.addComponent (newBasename);
  CPPUNIT_ASSERT (strcmp (pathTest.c_str(), "/some/path/to/repository/newname") == 0);

  svn::Path urlTest = "http://some/url/to/repository";
  std::string newFile = "newname";

  urlTest.addComponent (newFile);
  CPPUNIT_ASSERT (strcmp (urlTest.c_str(), "http://some/url/to/repository/newname") == 0);
}

void
PathTestCase::testCopy ()
{
  svn::Path pathOne = "/some/path";
  svn::Path pathTwo = pathOne;

  CPPUNIT_ASSERT (strcmp (pathOne.c_str (), pathTwo.c_str ()) == 0);
}

void
PathTestCase::testIsUrl ()
{
  svn::Path pathOne = "file:///this.is/a/url";
  CPPUNIT_ASSERT (pathOne.isUrl ());
  CPPUNIT_ASSERT (strcmp (pathOne.c_str (), "file:///this.is/a/url") == 0);
}

void
PathTestCase::testSubstr ()
{
  svn::Path test ("/home/sleepy/tmp/sf âê/Bla Bla Blubb");
  int length = 25;
  std::string result = "";

  result = test.substr (length);
  CPPUNIT_ASSERT (result == "Bla Bla Blubb");
}

void
PathTestCase::testUnescape ()
{
  svn::Path test ("/home/sleepy/tmp/sf%20x%20y");
  CPPUNIT_ASSERT (test.unescape () == "/home/sleepy/tmp/sf x y");
}

void
PathTestCase::testLength ()
{
  svn::Path test ("/tmp/sf%20x%20y");
  CPPUNIT_ASSERT (test.length () == 15);
}

/* -----------------------------------------------------------------
 * local variables:
 * eval: (load-file "../../../rapidsvn-dev.el")
 * end:
 */
