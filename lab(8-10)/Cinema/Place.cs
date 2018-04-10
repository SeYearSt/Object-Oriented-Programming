using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Cinema
{
    class Place
    {
        private int number;

        public int Number{
            get { return number; }
          //  set { number = value; }
        }

        private bool available;

        public void take()
        {
            if (available)
            {
                available = false;
            }
            else Console.WriteLine("Sorry this place is sold!");
        }
        public void cancel() {
            available = true;
        }
        public bool check() {
            return available;
         }
        public Place(int num) { number = num; available = true; }
        public Place() { number = -1; available = true; }
    }

}
