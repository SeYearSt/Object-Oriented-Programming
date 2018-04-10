using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Cinema
{
    class Schedule : Interface1
    {
        private Session[] arraySession;
        public Session[] ArraySession {
            get { return arraySession; }
            set { arraySession = value; }
        }
        public void output() {
           Console.Clear();
           Console.WriteLine("Id:    | Cinemahall:            | Movie:            | Begin:       | Duration:   ");
            Console.WriteLine("------------------------------------------------------------------------------");
            for (int i = 0; i < arraySession.Length; ++i) {
                Console.WriteLine("{0,-7}|{1,-24}|{2,-19}|              |{3,-13}", arraySession[i].Id, arraySession[i].HallName, arraySession[i].Name, arraySession[i].Duration);
                Console.WriteLine("------------------------------------------------------------------------------");
            }
            
        }
        private static Schedule instance;
        static public Schedule getInstance(Movie[] Movies, Cinemahall[] Cinemahalls) {
            if (instance == null) { instance = new Schedule(Movies , Cinemahalls); }
            return instance;
        }
      /*  public void output() {
            for (int i = 0; i < arraySession.Length; ++i) { arraySession[i].output(); }
        }*/
        private Schedule(Movie[] Movies, Cinemahall[] Cinemahalls)
        {
            arraySession = new Session[(Cinemahalls.Length*Movies.Length)];
            int k = 0;
            for (int i = 0; i < Cinemahalls.Length; ++i)
                for (int j = 0; j < Movies.Length; ++j)
                    {
                    arraySession[k++] = new Session(Cinemahalls[i],Movies[j]);
                    }
        }

    }
   
}
