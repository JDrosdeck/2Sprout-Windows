using System;
using System.Collections.Generic;

using System.Text;


    class SproutList
    {
        protected List<int> myList;
        protected Object myLockObj; 

        public SproutList()
        {
            myList = new List<int>();
            myLockObj = new Object(); 
        }

        public int Count
        {
            get
            {
                return myList.Count;
            }
            set
            { }
        }

        public void Clear()
        {
            lock(myLockObj)
            {
                myList.Clear(); 
            }
        }

        public void Add(int input)
        {
            lock (myLockObj)
            {
                myList.Add(input);
            }
        }

        public List<int> GetAndClear()
        {
            List<int> outList = new List<int>();
            lock (myLockObj)
            {
                outList.AddRange(myList); 
                myList.Clear(); 
            }
            return outList; 
        }
    }

