import urllib2
import time


while True:
    f = open('links.txt', 'r')
    g = f.readlines()

    for site in g:
        print site
        url = 'http://2sprout.com/announce/v1/?site=' + site
        print url
        launch = urllib2.urlopen(url)
        time.sleep(5)
        f.close()
