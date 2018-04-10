using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Cinema
{
    class Cashregister
    {
       static int inputInt (){
            bool result;
            int value;
          do {
             Console.WriteLine("Please input number!");
               string temp = Console.ReadLine();
               result = Int32.TryParse(temp, out value);
          } while (!result);
           return value;
       }
        static void drawPlaces(int idSession, ref Schedule oneSchedule) {
            Console.Clear();
            for (int i = 0; i < oneSchedule.ArraySession[idSession-1].Places.Length; ++i)
            {
                if (oneSchedule.ArraySession[idSession-1].Places[i].check()) { Console.Write(" {0}_ ", i); }
                else { Console.Write(" {0}X ", i); }
                if ((i+1) % 10 == 0) Console.WriteLine();
            }
        }
       static void SessionMenu(int idSession, ref Schedule oneSchedule)
       {
            
            drawPlaces(idSession, ref oneSchedule);
            Console.WriteLine("You are in cinemahall number: {0}", oneSchedule.ArraySession[idSession - 1].Id);
            Console.WriteLine("Input number of place to buy or input -1 to go in previous menu");
            int control;
            do
            {
                control = inputInt();
                switch (control)
                {
                    case -1: { break; }
                    default:
                        {
                            if (control >= 0 && control <= oneSchedule.ArraySession[idSession-1].Places.Length)
                            {
                                oneSchedule.ArraySession[idSession-1].Places[control].take();
                                drawPlaces(idSession, ref oneSchedule);
                                Console.WriteLine("You are in cinemahall number: {0}", oneSchedule.ArraySession[idSession - 1].Id);
                                Console.WriteLine("Input number of place to buy or input -1 to go in previous menu");
                            }
                            else { Console.WriteLine("Please input option or number place"); }
                            break;
                        }


                }
            } while (control != -1);
            Console.WriteLine("Please input number of place!");
       }
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

                Schedule oneSchedule = Schedule.getInstance(Movies, halls);

                //oneSchedule.output();

                Console.WriteLine("You are in switch menu now. Please choose next options");
                Console.WriteLine("To get list of sessions input 0");
                //  Console.WriteLine("Write session id and push Enter to have access to with session");

                int control;
                oneSchedule.output();
                do
                {
                    control = inputInt();
                    switch (control)
                    {
                        case 0: { oneSchedule.output(); break; }
                        case -1: { Console.WriteLine("To finish program push  any key!"); break; }
                        default:
                            {
                                if (control >= 1 && control <= oneSchedule.ArraySession.Length)
                                {
                                    SessionMenu(control, ref oneSchedule);
                                    oneSchedule.output();
                                    control = 0;
                                }
                                else
                                {
                                    Console.WriteLine("You are in switch menu now. Please choose next options");
                                    Console.WriteLine("To get list of sessions input 0");
                                }
                                break;
                            }
                    }
                } while (control != -1);
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
