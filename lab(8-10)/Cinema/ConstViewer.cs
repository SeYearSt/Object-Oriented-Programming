using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Cinema
{
    sealed class  ConstViewer :Viewer
    {
        int times;
        public static bool operator > (ConstViewer a, ConstViewer b)
        {
            return (a.times > b.times);
        }
        public static bool operator <(ConstViewer a, ConstViewer b)
        {
            return (a.times < b.times);
        }
    }
}
