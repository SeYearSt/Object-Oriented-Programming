using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Cinema
{
    class Cinemahall
    {
        static int variable;
        private string name;
        public string Name { get { return name; } }
        public int size;
        public int Size{
            get { return size; }
            private set { size = value; }
        }
        public Cinemahall(string name) {
            this.name = name;
            size = 30;
        }
        public Cinemahall(string name,int size) {
            this.name = name;
            this.size = size;
        }
        static Cinemahall() {
          variable = 0;
        }
        public Cinemahall(Cinemahall obj) {
            this.name = obj.Name;
            this.Size = obj.Size;
        }
    }
}
