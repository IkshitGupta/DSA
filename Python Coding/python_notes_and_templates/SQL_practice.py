from google.cloud import bigquery
client = bigquery.Client()
# In BigQuery, each dataset is contained in a corresponding project. In this case, our hacker_news dataset is contained in the bigquery-public-data project. To access the dataset,

# We begin by constructing a reference to the dataset with the dataset() method.
# Next, we use the get_dataset() method, along with the reference we just constructed, to fetch the dataset.
dataset_ref = client.dataset("hacker_news", project="bigquery-public-data")
# API request - fetch the dataset
dataset = client.get_dataset(dataset_ref)
# Every dataset is just a collection of tables. You can think of a dataset as a spreadsheet file containing multiple tables, all composed of rows and columns.
# Client objects hold projects and a connection to the BigQuery service.
# bigquery-public-data is a project. A project is a collection of datasets.
# hacker_news is a dataset. A dataset is a collection of tables.

# list_tables() method to list the tables in the dataset.
tables = list(client.list_tables(dataset))
# Print names of all tables in the dataset
for table in tables:  
    print(table.table_id)

# fetching a table like we fetched a dataset
# Construct a reference to the table named full
table_ref = dataset_ref.table("full")
# API request - fetch the table
table = client.get_table(table_ref)
# The structure of a table is called its schema. We need to understand a table's schema to effectively pull out the data we want.
table.schema
# Each Schema Field tells us about a specific column (which we also refer to as a field).
# The `name` of the column, The `field_type` (or datatype) in the column, The `mode` of the column ('NULLABLE' means that a column allows NULL values, and is the default), A `description` of the data in that column
# we can iterate in table.schema where each entry is a object with arguments under quotes above
# We can use the list_rows() method to check just the first five lines of of the table
client.list_rows(table, max_results=5).to_dataframe()
# to_dataframe converts to pandas DataFrame (to view it as list_rows return a row iterator)
client.list_rows(table, selected_fields=table.schema[:1], max_results=5).to_dataframe() # specific columns

# SQL queries
# SELECT...FROM
# specify the column you want after the word SELECT, and then
# specify the table after the word FROM.
# For instance, to select the Name column (from the pets table in the pet_records database in the bigquery-public-data project), our query would appear as follows:
# """ tell Python that everything inside them is a single string, even though we have line breaks in it. The line breaks aren't necessary, but they make it easier to read your query.
# not necessary to capitalize
query = """ 
        SELECT Name
        FROM `bigquery-public-data.pet_records.pets`
        WHERE Animal = 'Cat'
        """
# the argument we pass to FROM is in backtick ``
query_job = client.query(query)
us_cities = query_job.to_dataframe()
us_cities.city.value_counts().head()    # pandas dataframe

# Create a QueryJobConfig object to estimate size of query without running it
dry_run_config = bigquery.QueryJobConfig(dry_run=True)
dry_run_query_job = client.query(query, job_config=dry_run_config)
dry_run_query_job.total_bytes_processed
ONE_MB = 1000*1000
safe_config = bigquery.QueryJobConfig(maximum_bytes_billed=ONE_MB)
safe_query_job = client.query(query, job_config=safe_config)
safe_query_job.to_dataframe()
# query will not run if exceeds size

# SELECT DISTINCT name
# will select entries with distinct name

query = """
      SELECT COUNT(ID)
       FROM`bigquery-public-data.pet_records.pets`
       """
# COUNT() is an example of an aggregate function, which takes many values and returns one. (Other examples of aggregate functions include SUM(), AVG(), MIN(), and MAX().)
# query returns a strange column name such as f0 with ans
# GROUP BY takes the name of one or more columns, and treats all rows with the same value in that column as a single group when you apply aggregate functions like COUNT().

query="""
      SELECT Animal,COUNT(ID)
      FROM`bigquery-public-data.pet_records.pets`
      GROUP BY Animal
      """
# Animal fo
# Rabbit  1
# Dog     1
# Cat     2

# HAVING is used in combination with GROUP BY to ignore groups that don't meet certain criteria
query="""
      SELECT Animal,COUNT(ID) AS AnimalCount
       FROM`bigquery-public-data.pet_records.pets
      GROUP BY Animal
      HAVING COUNT(ID)>1
      """
# AS avoid f0
#  it doesn't make sense to use GROUP BY without an aggregate function
# do COUNT(1) to count the rows in each group

# ORDER BY is usually the last clause in your query, and it sorts the results returned by the rest of your query.
# You can reverse the order using the DESC argument 
# order by Animal DESC

# Date format YYYY-[M]M-[D]D
# YYYY: Four-digit year, [M]M: One or two digit month, [D]D: One or two digit day
# The DATETIME format is like the date format ... but with time added at the end.
# SELECT Name,EXTRACT(WEEK from Date)AS Week
# week number is extracted, similarly can extract other things like day, month, year, hour, dayofweek(1 to 7)

# in where clause `and` or `or` used &, | not used

# A common table expression (or CTE) is a temporary table that you return within your query. CTEs are helpful for splitting your queries into readable chunks, and you can write queries against them.
# Also, it's important to note that CTEs only exist inside the query where you create them, and you can't reference them in later queries. So, any query that uses a CTE is always broken into two parts: (1) first, we create the CTE, and then (2) we write a query that uses the CTE.
query="""
       WITH Seniors AS
      (
         SELECT ID,Name
         FROM`bigquery-public-data.pet_records.pets`
         WHERE Years_old>5
      )
      SELECT ID
       FROM Seniors
       """

# SELECT DATE(block_timestamp) AS trans_date
# block_timestamp in datetime format date() method used to convert to date format

# join
query="""
       SELECT p.Name AS Pet_Name,o.Name AS Owner_Name
       FROM`bigquery-public-data.pet_records.pets AS p
       INNER JOIN `bigquery-public-data.pet_records.owners` AS o
           ON p.ID=o.Pet_ID
       """
# We combine information from both tables by matching rows where the ID column in the pets table matches the Pet_ID column in the owners table.
# to create a table containing all rows from the owners table, we use a LEFT JOIN, i.e. owner before inner join

# INNER JOIN : all rows from first tale with matching entries given in INNER JOIN
# LEFT JOIN : all rows where the two tables have matching entries, along with all of the rows in the left table (whether there is a match or not)
# RIGHT JOIN : matching rows, along with all rows in the right table (whether there is a match or not).
# FULL JOIN : all rows from both tables. Note that in general, any row that does not have a match in both tables will have NULL entries for the missing values

# UNION
# JOINs horizontally combine results from different tables. If you instead would like to vertically concatenate columns, you can do so with a UNION
query="""
      SELECT Age FROM`bigquery-public-data.pet_records.pets
      UNION ALL
      SELECT Age FROM`bigquery-public-data.pet_records.owners
      """
# UNION, the data types of both columns must be the same, but the column names can be different
# owner name Age pet name age   two table
# owner name Age pet name
# UNION ALL take all
# UNION DISTINCT take unique
# Combine records from multiple result sets
# Query to select all users who posted stories or comments on January 1, 2014
union_query = """
              SELECT c.by
              FROM `bigquery-public-data.hacker_news.comments` AS c
              WHERE EXTRACT(DATE FROM c.time_ts) = '2014-01-01'
              UNION DISTINCT
              SELECT s.by
              FROM `bigquery-public-data.hacker_news.stories` AS s
              WHERE EXTRACT(DATE FROM s.time_ts) = '2014-01-01'
              """
# MIN(TIMESTAMP_DIFF(a.creation_date, q.creation_date, SECOND))
# min difference in timestamps in terms of second

# LIKE
# WHERE first_name LIKE '%bigquery%'
# both single quotes