using System;
using System.Collections.Generic;
using System.Text;
//using System.Security.Cryptography;

    class Convert
    {
        private Convert() { }
        /// <summary>
        /// Take a string and encode it in base 64. 
        /// </summary>
        /// <param name="toEncode">String to be encoded. </param>
        /// <returns>Input string encoded in base 64.</returns>
        static public string EncodeTo64(string toEncode) 
        {
            byte[] toEncodeAsBytes = System.Text.ASCIIEncoding.ASCII.GetBytes(toEncode);

            string returnValue = System.Convert.ToBase64String(toEncodeAsBytes);

            return returnValue;
        }

        /// <summary>
        /// Take a base 64 string and decode it back to ascii. 
        /// </summary>
        /// <param name="encodedData">Base 64 string to be decoded. </param>
        /// <returns>Input string decoded to ascii.</returns>
        /// <exception cref="System.FormatException"></exception>
        static public string DecodeFrom64(string encodedData)
        {
            byte[] encodedDataAsBytes; 
            try
            {
                encodedDataAsBytes = System.Convert.FromBase64String(encodedData);
            }
            catch (FormatException)
            {
                return ""; 
            }
            string returnValue = System.Text.ASCIIEncoding.ASCII.GetString(encodedDataAsBytes);

            return returnValue;
        }

        public static string EncryptDecrypt(string textToEncrypt, String key)
        {
            StringBuilder inSb = new StringBuilder(textToEncrypt);
            StringBuilder outSb = new StringBuilder(textToEncrypt.Length);
            char c;

            for (int i = 0, j = 0; i < textToEncrypt.Length; i++)
            {
                c = inSb[i];
                c = (char)(c ^ key[j++]);
                outSb.Append(c);
                if (j >= key.Length)
                    j = 0;
            }
            return outSb.ToString();
        }

        public static bool IsIPv4(String addressIn)
        {
            byte hold; 
            String [] addressParts = addressIn.Split(new char[1] {'.'});
            if (addressParts.Length != 4)
                return false;
            for (int i = 0; i < 4; i++)
            {
                if(!byte.TryParse(addressParts[i], out hold))
                {
                    return false; 
                }
            }
            return true; 
        }
    }
