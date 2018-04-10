using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Cinema
{
    class Cashregister
    {
        static void Main(string[] args)
        {
            try
            {
                int count = (File.ReadAllLines("ListOfMovies.txt").Length) / 3;

                StreamReader file = new StreamReader("ListOfMovies.txt");

                Movie[] Movies = new Movie[count];
                for (int i = 0; i < count; ++i)
                {
                    Movies[i] = new Movie();
                }
                Movie.fillMovies(ref file, ref Movies);
                // for (int i = 0; i < count; ++i) { Movies[i].output(); }
                file.Close();
                Cinemahall[] halls = new Cinemahall[2];

                halls[0] = new Cinemahall("GreenHall");
                halls[1] = new Cinemahall("YellowHall", 40);

                Schedule oneShedule = Schedule.getInstance(Movies,halls);
 
                oneShedule.output();


                int numberSession, numberPlace;
                Console.WriteLine("Please Input number of session!");
                numberSession = Convert.ToInt32(Console.ReadLine());
                oneShedule.ArraySession[numberSession - 1].output();

                for (int i = 0; i < oneShedule.ArraySession[numberSession - 1].CountPlaces; ++i)
                {
                    if (i % 10 == 0) Console.WriteLine();
                    if (oneShedule.ArraySession[numberSession - 1].Places[i].check())
                    {
                        Console.Write($" {i}_ ");
                    }
                    else Console.Write($" {i}X ");
                }

                Console.WriteLine("Please Input number of place");
                numberPlace = Convert.ToInt32(Console.ReadLine());
                oneShedule.ArraySession[numberSession - 1].places[numberPlace].take();
                for (int i = 0; i < oneShedule.ArraySession[numberSession - 1].CountPlaces; ++i)
                {
                    if (i % 10 == 0) Console.WriteLine();
                    if (oneShedule.ArraySession[numberSession - 1].Places[i].check())
                    {
                        Console.Write($" {i}_ ");
                    }
                    else Console.Write($" {i}X ");
                }

                Console.ReadKey();

            }
            catch (IOException e)
            {
                Console.WriteLine(e.Message);
                Console.Read();
            }

           
        }
    }
}
