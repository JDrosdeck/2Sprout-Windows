using System;
using System.Collections.Generic;
using System.Text;

    class SproutQueue
    {
        protected Queue<String> myQueue;
        protected Object myLockObj;

        public SproutQueue()
        {
            myQueue = new Queue<String>(); 
            myLockObj = new Object(); 
        }

        public int Count
        {
            get
            {
                return myQueue.Count; 
            }
            set { }
        }

        public void Enqueue(String input)
        {
            lock (myLockObj)
            {
                myQueue.Enqueue(input); 
            }
        }

        public String Dequeue()
        {
            String output;
            lock (myLockObj)
            {
                output = myQueue.Dequeue(); 
            }
            return output;  
        }
    }
