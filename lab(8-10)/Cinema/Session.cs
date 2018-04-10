using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Cinema
{
    class Session : Movie
    {
        static private int count = 0;
        private int id;
        public int Id { get { return id; } private set { id = value; } }
        private string hallName;
        public string HallName {
            get { return hallName; }
            private set { hallName = value; }
        }
        private string start;
        public Place[] places;
        public Place[] Places {
            get { return places; }
            private set { places = value; }
        }
        private int countPlaces;
        public int CountPlaces {
            get { return countPlaces; }
        }
        public override void output() {
            Console.WriteLine("ID: {0}\nHall: {1}\nMovies: {2}\nBegining: {3}\nDuration: {4}\nCategory: {5}\nCount of places: {6}\n------------------------", id, hallName, movieName, start, duration,category,countPlaces);
        }
        public Session(Cinemahall CinemahallInstance,Movie MovieInstance)
        {
            ++count;
            id = count;
            places = new Place[CinemahallInstance.Size];
            for (int i = 0; i < CinemahallInstance.Size; ++i) {
                places[i] = new Place();
            }
            hallName = CinemahallInstance.Name;
            movieName = MovieInstance.Name;
            duration = MovieInstance.Duration;
            category = MovieInstance.Category;
            countPlaces = CinemahallInstance.Size;
            start = "\0";
        }
    }
    
}
