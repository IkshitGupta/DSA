import seaborn as sns
import pandas as pd
import matplotlib.pyplot as plt
fifa_filepath = "../input/fifa.csv"
fifa_data = pd.read_csv(fifa_filepath, index_col="Date", parse_dates=True)
            # filepath to dataset     column to use     recognize the row
                                #   as row labels        labels as dates                   
# 	            ARG	 BRA  ESP FRA  GER	ITA
# Date						
# 1993-08-08	5.0	 8.0 13.0 12.0 1.0	2.0
# 1993-09-23	12.0 1.0 14.0 7.0  5.0	2.0

# Line Charts
# Visualize trend over time
spotify_data = ''
plt.figure(figsize=(14,6))
plt.title("Daily Global Streams of Popular Songs in 2017-2018")
sns.lineplot(data=spotify_data)

list(spotify_data.columns)  # printing all column names
sns.lineplot(data=spotify_data['Shape of You'], label="Shape of You")
sns.lineplot(data=spotify_data['Despacito'], label="Despacito")
# line plot of two columns out of all

# barplot
# shows the average of the column
flight_filepath = ''
flight_data = pd.read_csv(flight_filepath, index_col="Month")
# 'Month' column don't correspond to dates, we don't add parse_dates=True
sns.barplot(x=flight_data.index, y=flight_data['NK'])
# You must select the indexing column with flight_data.index, and it is not possible to use flight_data['Month'] as it is no longer a column
sns.heatmap(data=flight_data, annot=True)
# This ensures that the values for each cell appear on the chart. (Leaving this out removes the numbers from each of the cells!)
# A heat map is a data visualization technique that shows magnitude of a phenomenon as color in two dimensions. The variation in color may be by hue or intensity, giving obvious visual cues to the reader about how the phenomenon is clustered or varies over space
# the heat map shows the relative intensity of values captured by your eye tracker by assigning each value a color representation
insurance_data = ''
sns.scatterplot(x=insurance_data['bmi'], y=insurance_data['charges'])
# positively correlated, where customers with higher BMI typically also tend to pay more in insurance costs.
sns.regplot(x=insurance_data['bmi'], y=insurance_data['charges'])
# positive slope, positive corelation
# to add a regression line, or the line that best fits the data.
# We can use scatter plots to display the relationships between (not two, but...) three variables
sns.scatterplot(x=insurance_data['bmi'], y=insurance_data['charges'], hue=insurance_data['smoker'])
# x axis, y axis, scatter points
# suppose smoker has 2 entries yes and no, both will be differently color coded
# sns.lmplot command to add two regression lines, corresponding to smokers and nonsmokers.
sns.lmplot(x="bmi", y="charges", hue="smoker", data=insurance_data) # takes column name
sns.swarmplot(x=insurance_data['smoker'], y=insurance_data['charges']) # categorical scatter plot
# two (yes no entries of smoker) scatter plots in parallel one with yes and one with no

iris_data = ''
sns.histplot(iris_data['Petal Length (cm)'])    # entry one se 2 me kitne bar 2 se 3 me kitne bar
# vs count

# kernel density estimate (KDE) plot. In case you're not familiar with KDE plots, you can think of it as a smoothed histogram.
sns.kdeplot(data=iris_data['Petal Length (cm)'], shade=True)
# We're not restricted to a single column when creating a KDE plot. We can create a two-dimensional (2D) KDE plot with the sns.jointplot command.
sns.jointplot(x=iris_data['Petal Length (cm)'], y=iris_data['Sepal Width (cm)'], kind="kde")
# combination of 3 graphs
# center -: how likely we are to see different combinations of sepal width and petal length
# on x axis iris_data['Petal Length (cm)']
# on y axis iris_data['Sepal Width (cm)']

# x= sets the name of column with the data we want to plot
# hue= sets the column we'll use to split the data into different histograms
sns.histplot(data=iris_data, x='Petal Length (cm)', hue='Species')
sns.kdeplot(data=iris_data, x='Petal Length (cm)', hue='Species', shade=True)
# shade -: below the curve shading is done

sns.set_style("dark")
# Seaborn has five different themes: (1)"darkgrid", (2)"whitegrid", (3)"dark", (4)"white", and (5)"ticks"
# ticks is like normal white one with tick marks on axis

"""
Trends - A trend is defined as a pattern of change.
sns.lineplot - Line charts are best to show trends over a period of time, and multiple lines can be used to show trends in more than one group.
Relationship - There are many different chart types that you can use to understand relationships between variables in your data.
sns.barplot - Bar charts are useful for comparing quantities corresponding to different groups.
sns.heatmap - Heatmaps can be used to find color-coded patterns in tables of numbers.
sns.scatterplot - Scatter plots show the relationship between two continuous variables; if color-coded, we can also show the relationship with a third categorical variable.
sns.regplot - Including a regression line in the scatter plot makes it easier to see any linear relationship between two variables.
sns.lmplot - This command is useful for drawing multiple regression lines, if the scatter plot contains multiple, color-coded groups.
sns.swarmplot - Categorical scatter plots show the relationship between a continuous variable and a categorical variable.
Distribution - We visualize distributions to show the possible values that we can expect to see in a variable, along with how likely they are.
sns.histplot - Histograms show the distribution of a single numerical variable.
sns.kdeplot - KDE plots (or 2D KDE plots) show an estimated, smooth distribution of a single numerical variable (or two numerical variables).
sns.jointplot - This command is useful for simultaneously displaying a 2D KDE plot with the corresponding KDE plots for each individual variable.
"""