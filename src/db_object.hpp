/*
   Copyright 2011 Carl Anderson

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#ifndef __ASH_DB_OBJECT__
#define __ASH_DB_OBJECT__

#include <list>
#include <map>
#include <string>

using std::list;
using std::map;
using std::string;

namespace ash {


/* abstract */
class DBObject {
  public:
    static const string quote(const char * value);
    static const string quote(const string & value);
    static const string get_create_tables();
    static void register_table(const string & create_statement);

  protected:
    static list<string> create_tables;

  protected:
    DBObject();
    virtual ~DBObject();

    virtual const string get_name() const = 0;  // abstract
    virtual const string get_sql() const;

    map<string, string> values;

  private:
    DBObject(const DBObject & other);  // disabled
    DBObject & operator =(const DBObject & other);  // disabled
};


}  // namespace ash

#endif /* __ASH_DB_OBJECT__ */
