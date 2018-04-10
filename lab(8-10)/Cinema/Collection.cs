using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Cinema
{
    class Collection
    {
        List<Movie> array;

        public Collection()
        {
            array = new List<Movie>();
        }

        public Movie this[string name]
        {
            get
            {
                if (array.FindIndex(x => x.Name == name) > -1)
                    return array[array.FindIndex(x => x.Name == name)];
                else
                {
                    array.Add(new Movie(name, 0));
                    return array[array.Count - 1];
                }
            }
            set
            {
                if(array.FindIndex(x => x.Name == name)>-1)
                    array[array.FindIndex(x => x.Name == name)] = value;
            }
        }

        public List<Movie> getCollectionAsList()
        {
            return this.array;
        }

        public void getCollectionFromList(List<Movie> array)
        {
            this.array = array;
        }
    
    }
}