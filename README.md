1. SQL Parser -- Classify into four type
	a. Update
	b. Insert
	c. Delete
	d. Create
	e. Select
	f. Use

2. How are tables stored and created?
	a. One main class called Database
		i. Will have a list of all table classes
	b. Tables class
		i. Each datatype will be a class (Number, Date, Varchar etc.)
		ii. Each data value will be an instance of the above
		iii. Will hold one primary key attribute
		iv. (Optional) Foreign keys
	c. When a `create` command is executed, we will create a new class which inherits the `Table` class
	d. Database object is created when the program is launched, tables of a specific database are loaded into the object when `use` is used.
		OR 
		When Boost::Serialization to store the object of a specific database directly.

3. How are tables interacted with?
	a. When a `select`, `insert`, `update`, `delete` command is issue we will look for the table in Database object
	b. When a table is found, we transfer it to main memory using a `TableExtractor` class
	c. We will send the table to a specific `Processor` module
	d. Any changes to the database tables (Pending)

4. Physical level
	a. Use the created table classes to get the database memory scheme
	b. Use pagers and cursors to traverse the database
	c. Use a B-tree for efficient hardware storage

