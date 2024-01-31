using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using pz18;

namespace pz18
{
        public class Student
        {
            public string Name { get; set; }
            public string Group { get; set; }

            public override string ToString()
            {
                return $"студент {this.Name} из группы {this.Group}";
            }
        }
}
