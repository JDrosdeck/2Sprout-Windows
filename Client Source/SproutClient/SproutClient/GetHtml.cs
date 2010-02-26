using System;
using System.Collections.Generic;
using System.Text;
using System.Net;
using System.Threading; 

    class GetHtml
    {
        ErrorLog errorLog; 

        public GetHtml(ErrorLog log) 
        { 
            errorLog = log; 
        }

        /// <summary>
        /// Html Get request with unlimited access attempts. 
        /// </summary>
        /// <param name="url">Web url to be accessed.</param>
        /// <returns>Page HTML if access was successful, otherwise will return a blank string.</returns>
        public String GetRequest(String url)
        {
            return getHtml(url, null, int.MaxValue); 
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="url">Web url to be accessed.</param>
        /// <param name="attempts">Access attempts before a blank string is returned. </param>
        /// <returns>Page HTML if access was successful, otherwise will return a blank string.</returns>
        public String GetRequest(String url, int attempts)
        {
            return getHtml(url, null, attempts); 
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="url">Web url to be accessed.</param>
        /// <param name="post">Post information. </param>
        /// <returns>Page HTML if access was successful, otherwise will return a blank string.</returns>
        public String PostRequest(String url, String post)
        {
            return getHtml(url, post, int.MaxValue); 
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="url">Web url to be accessed.</param>
        /// <param name="post">POST information. </param>
        /// <param name="attempts">Access attempts before a blank string is returned.</param>
        /// <returns>Page HTML if access was successful, otherwise will return a blank string.</returns>
        public String PostRequest(String url, String post, int attempts)
        {
            return getHtml(url, post, attempts); 
        }

        /// <summary>
        /// Private accessor for all GET and POST requests.
        /// </summary>
        /// <param name="url">Web url to be accessed.</param>
        /// <param name="post">Place POST request information here. If a GET request, use null. </param>
        /// <param name="attempts"># of attemtps before sending back an empty string.</param>
        /// <returns>Page HTML if access was successful, otherwise will return a blank string. </returns>
        private String getHtml(String url, String post, int attempts)
        {
            WebClient webClient = new WebClient();
            UTF8Encoding utfObj = new UTF8Encoding();
            byte[] reqHTML;

            while (attempts > 0)// Will keep trying to access until attempts reach zero.
            {
                try
                {
                    if (post != null) //If post is null, then no post request is required. 
                        reqHTML = webClient.UploadData(url, "POST", System.Text.Encoding.ASCII.GetBytes(post));
                    else
                        reqHTML = webClient.DownloadData(url);
                    String input = utfObj.GetString(reqHTML);
                    return input;
                }
                catch (WebException e)
                {
                    errorLog.WriteMessage("Could not contact to " + url + "  -  " + e.Message);
                    Thread.Sleep(2000);
                }
                catch (ArgumentNullException e)
                {
                    errorLog.WriteMessage("Could not retrieve data from " + url + "  -  " + e.Message);
                    Thread.Sleep(2000);
                }
                attempts--; 
            }
            return ""; 
        }
    }