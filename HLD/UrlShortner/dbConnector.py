import psycopg2


class db_connector:

    def __init__(self):

        DB_NAME = "testdb"
        DB_USER = "testuser"
        DB_PASS = "test@123"
        DB_HOST = "localhost"
        DB_PORT = "5432"




        try:
            self.conn = psycopg2.connect(database=DB_NAME,
                                    user=DB_USER,
                                    password=DB_PASS,
                                    host=DB_HOST,
                                    port=DB_PORT)
            print("Database connected successfully")
        except:
            print("Database not connected successfully")


    def get_tiny(self,long_url):
        try:
            cur = self.conn.cursor()
            cur.execute("select * from url.url_details where long_url = '" + long_url + "' ;")
            rows = cur.fetchall()
            for row in rows:
                return True,str(row[0])

        except psycopg2.Error as err:
            print(err)

        return False,''

    def get_original(self,tiny_url):
        try:
            cur = self.conn.cursor()
            cur.execute("select * from url.url_details where short_url = '" + tiny_url + "' ;")
            rows = cur.fetchall()
            for row in rows:
                return True,str(row[1])

        except psycopg2.Error as err:
            print(err)

        return False,''

    def update_time(self,tiny_url):
        try:
            cur = self.conn.cursor()
            cur.execute("UPDATE url.url_details set created_on = now() WHERE short_url = '" + tiny_url + "' ")
            self.conn.commit()
        except psycopg2.Error as err:
            print(err)


    def insert(self,tiny_url,long_url):
        try:
            cur = self.conn.cursor()
            cur.execute("insert into url.url_details  values ( '" +  tiny_url + "', '" + long_url + "',now())" )
            self.conn.commit()
            print("Data Inserted Successfully")
            return True
        except psycopg2.Error as err:
            print('Exception = ',err)
            return False

