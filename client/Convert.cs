using System;
using System.Collections.Generic;
using System.Text;
//using System.Security.Cryptography;

    class Convert
    {
        public static String CalcCheckSum(String text)
        {
            int ascii = 0;
            for (int i = 0; i < text.Length; i++)
            {
                ascii += (int)text[i]; 
            }
            return ascii.ToString(); 
        }

        /*public static String GetMD5(String input)
        {
            byte[] bs;
            StringBuilder s;
            MD5CryptoServiceProvider x = new MD5CryptoServiceProvider();

            bs = System.Text.Encoding.UTF8.GetBytes(input);
            bs = x.ComputeHash(bs);
            s = new StringBuilder();
            foreach (byte b in bs)
            {
                s.Append(b.ToString("x2").ToLower());
            }
            return s.ToString();
        }*/

        static public string EncodeTo64(string toEncode)
        {
            byte[] toEncodeAsBytes = System.Text.ASCIIEncoding.ASCII.GetBytes(toEncode);

            string returnValue = System.Convert.ToBase64String(toEncodeAsBytes);

            return returnValue;
        }


        static public string DecodeFrom64(string encodedData)
        {
            byte[] encodedDataAsBytes = System.Convert.FromBase64String(encodedData);

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
