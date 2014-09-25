import sys.db.Types;

class Test {
    static function main() {
        // Open a connection
        var cnx = sys.db.Sqlite.open("mybase.db");

        // Set as the connection for our SPOD manager
        sys.db.Manager.cnx = cnx;

        // Create the "user" table
        sys.db.TableCreate.create(User.manager);

        // Set up our first two users
        var user1 = new User();
        user1.name = "Jason O'Neil";
        user1.birthday = new Date(1987,10,16,0,0,0);
        user1.phoneNumber = "(08) 9350 0000";

        var user2 = new User();
        user2.name = "Anna O'Neil";
        user2.birthday = new Date(1990,02,21,0,0,0);
        user2.phoneNumber = null;

        // Insert these two users into our database
        user1.insert();
        user2.insert();
        
        // Close the connection
        cnx.close();
    }
}

class User extends sys.db.Object {
    public var id : SId;
    public var name : SString<32>;
    public var birthday : SDate;
    public var phoneNumber : SNull<SText>;
}