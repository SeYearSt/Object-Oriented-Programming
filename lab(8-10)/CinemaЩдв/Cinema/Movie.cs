using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Cinema
{

   public class Movie
    {
        static public void fillMovies(ref StreamReader file, ref Movie[] Movies)
        {
            for (int i = 0; i < Movies.Length; ++i)
            {
                Movies[i].movieName = file.ReadLine();
                int.TryParse(file.ReadLine(), out Movies[i].duration);
                Movies[i].category = file.ReadLine();
            }

        }

        protected string movieName;
         public string Name
        {
            get { return movieName; }
        }

        protected int duration;
          public int Duration
        {
            get { return duration; }
        }

        protected string category;

          public string Category {
              get { return category; }
            /*  set { if (category == "A" || category == "B" || category == "C" || category == "D" )
                    {
                            category = value;
                    }
                    else Console.WriteLine("Sorry you choose wrong category! Please choose between 'A','B','C','D'");
            }*/
          }
        public virtual void output() {
            Console.WriteLine("Film`s name: {0}", movieName);
            Console.WriteLine("Film`s duration: {0}", duration);
            Console.WriteLine("Film`s category: {0}", category);
        }
        public  Movie () {
            movieName = "\0";
            duration = 0;
            category = "\0";
        }
         public Movie(string movieName, int duration, string category) {
            if (duration < 0) { duration = 0; Console.WriteLine("Film duration cannot has sign"); }
            else {
                this.movieName = movieName;
                if (category == "A" || category == "B" || category == "C" || category == "D")
                {
                    this.category = category;
                }
                else Console.WriteLine("Sorry you choose wrong category! Please choose between 'A','B','C','D'");
            }
           
        }
        public Movie (string movieName, int duration)
        {
            if (duration < 0) { duration = 0; Console.WriteLine("Film duration cannot be "); }
        }
    }
    
}