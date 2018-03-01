## SQL Parser -- Classify into six type
a. Update
b. Insert
c. Delete
d. Create
e. Select
f. Use

## How are tables stored and created?
#### One main class called Database
Will have a list of all table classes
#### Table class
a. Each datatype will be a class (Number, Date, Varchar etc.)
b. Each data value will be an instance of the above
c. Will hold one primary key attribute
d. (Optional) Foreign keys


When a `create` command is executed, we will create a new class which inherits the `Table` class

Database object is created when the program is launched, tables of a specific database are loaded into the object when `use` is used.
	OR 
When Boost::Serialization to store the object of a specific database directly.

## How are tables interacted with?
a. When a `select`, `insert`, `update`, `delete` command is issue we will look for the table in Database object
b. When a table is found, we transfer it to main memory using a `TableExtractor` class
c. We will send the table to a specific `Processor` module
d. Any changes to the database tables (Pending)

## Physical level
a. Use the created table classes to get the database memory scheme
b. Use pagers and cursors to traverse the database
c. Use a B-tree for efficient hardware storage

