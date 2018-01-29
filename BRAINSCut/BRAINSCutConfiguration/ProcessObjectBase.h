/*=========================================================================
 *
 *  Copyright SINAPSE: Scalable Informatics for Neuroscience, Processing and Software Engineering
 *            The University of Iowa
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/
#ifndef ProcessObjectBase_H
#define ProcessObjectBase_H
#include <string>
#include <iostream>

class ProcessObjectException
{
public:
  ProcessObjectException(const char *errorString)
  {
    this->m_ErrorString = errorString;
  }

  ProcessObjectException(const std::string & errorString)
  {
    this->m_ErrorString = errorString;
  }

  const std::string & Error() const
  {
    return m_ErrorString;
  }

private:
  std::string m_ErrorString;
};

class ProcessObjectBase
{
public:
  ProcessObjectBase(const std::string & name)
  {
    this->SetName(name);
  }

  ProcessObjectBase()
  {
  }

  virtual ~ProcessObjectBase()
  {
  }

  virtual bool Verify() constexpr  = 0;

  std::string PrintSpaces(const int howmany) const
  {
    std::string spaces("");

    for( int i = 0; i < howmany; i++ )
      {
      spaces = spaces + " ";
      }
    return spaces;
  }

  virtual int PrintSelf(std::ostream & os, int indent) constexpr  = 0;

  const std::string & GetName() const
  {
    return m_Name;
  }

  void SetName(const std::string & s)
  {
    m_Name = s;
  }

private:
  std::string m_Name;
};

template <typename OutputType>
class XMLContents :
  public ProcessObjectBase
{
public:
  typedef ProcessObjectBase SuperClass;
  virtual int PrintSelf(std::ostream &, int indent) const
  {
    // SuperClass::PrintSelf(os);
    // os << this->PrintSpaces(indent) << "=== XMLContents ===" <<
    // std::endl;
    // return indent+2;
    return indent;
  }

  XMLContents(const std::string & s) :
    ProcessObjectBase(s)
  {
  }

  XMLContents()
  {
  }

  virtual ~XMLContents()
  {
  }

  virtual OutputType GetValue(void) constexpr  = 0;
};

#endif // ProcessObjectBase_H
