using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Cinema
{
    class Schedule
    {
        private Session[] arraySession;
        public Session[] ArraySession {
            get { return arraySession; }
            set { arraySession = value; }
        }
        public void output() {
           Console.Clear();
           Console.WriteLine("Id:    | Cinemahall:            | Movie:            | Begin:            | Duration:   ");
            for (int i = 0; i < arraySession.Length; ++i) {
                Console.WriteLine("{0,7}|{1,-24}|{2,-19}|                   |{3,-13}", arraySession[i].Id, arraySession[i].HallName, arraySession[i].Name, arraySession[i].Duration);
            }
            /*
            Console.WrilteLine("")*/
              /* for (int i = 0; i <3; ++i) {
                Console.Write("Session Id: {0,-25}|", arraySession[i].Id);
                if ((i+1) % 3 == 0) Console.WriteLine();
            }
            Console.WriteLine();
            for (int i = 0; i < arraySession.Length; ++i)
            {
                Console.Write("Movies : {0,-25}|", arraySession[i].Name);
                if ((i + 1) % 3 == 0) Console.WriteLine();
            }
            Console.WriteLine();*/
           /* for (int i = 0; i < arraySession.Length; ++i)
            {
                Console.Write($"Movie duration: {arraySession[i].HallName}");
            }
            Console.WriteLine();
            for (int i = 0; i < arraySession.Length; ++i)
            {
                Console.Write($"Movie duration: {arraySession[i].Duration}");
            }
            Console.WriteLine();
            for (int i = 0; i < arraySession.Length; ++i)
            {
                Console.Write($"Movie category: {arraySession[i].Category}");
            }
            Console.WriteLine();
            for (int i = 0; i < arraySession.Length; ++i)
            {
                Console.Write($"Movie category: {arraySession[i].Category}");
            }*/
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
