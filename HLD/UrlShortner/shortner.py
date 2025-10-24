from dbConnector import db_connector
import zlib
import string

class Shortner:

    def __init__(self):
        self.db_obj = db_connector()
        self.prefix_url = "www.chotuurl.com"
        pass

    def to_base62(self,num):

        chars = string.digits + string.ascii_letters # this gets 62 chars

        if num == 0:
            return chars[0] #returns '0'

        base62 = []

        while num > 0:
            num,rem = divmod(num,62)
            base62.append(chars[rem])
        

        #finally reverse
        return "".join(reversed(base62))


    def get_tiny_url(self,long_url):
        hashed_value = zlib.crc32(long_url.encode())
        return self.prefix_url + '/' + self.to_base62(hashed_value)


    def generate_tiny_url(self,long_url):
        
        is_present,tiny_url = self.db_obj.get_tiny(long_url)

        if is_present:
            self.db_obj.update_time(tiny_url)
            return tiny_url

        # add collision Checka
        tiny_url = self.get_tiny_url(long_url)
        if self.db_obj.insert(tiny_url,long_url) == False:
            return "Cant Create"
        print('Here')
        return tiny_url



    def get_original_url(self,short_url):
        #is_present,tiny_url = self.db_obj.get_long_url(long_url):
        is_present,long_url = self.db_obj.get_original(short_url)
        return long_url

