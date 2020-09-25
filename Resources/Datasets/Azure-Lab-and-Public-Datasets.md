
# Azure Lab and Public Datasets

### This is a summary of the datasets used in Azure Machine Learning Foundation Course, order by course session with duplicates.  Some are direct download links, some are the source link of the original data. Feel free to use it for further exploration!

### Lab 2.23 Train a Linear Regression Model (Azure Open Dataset): 

#### Summary:
In this lab, we will be using a subset of NYC Taxi & Limousine Commission - green taxi trip records available from Azure Open Datasets. The data is enriched with holiday and weather data. Based on the enriched dataset, we will learn to use the Azure Machine Learning Graphical Interface to process data, build, train, score, and evaluate a regression model to predict NYC taxi fares. 

**Download dataset:**
https://introtomlsampledata.blob.core.windows.net/data/nyc-taxi/nyc-taxi-sample-data.csv


### Lab 3.4 Import, Transform, and Export Data: 

#### Summary:
The following exercise focuses on the Import Data module to load data into a machine learning pipeline from several datasets that will be merged and restructured. We will be using some sample data from the UCI dataset repository to demonstrate how you can perform basic data import transformation steps with the modules available in Azure Machine Learning designer.

**Download datasets:**<br>
https://introtomlsampledata.blob.core.windows.net/data/crime-data/crime-dirty.csv<br>
https://introtomlsampledata.blob.core.windows.net/data/crime-data/crime-spring.csv<br>
https://introtomlsampledata.blob.core.windows.net/data/crime-data/crime-winter.csv


### Lab 3.9 Create and Version a Dataset: 

#### Summary:
In this lab, we are using a subset of NYC Taxi & Limousine Commission - green taxi trip records available from Azure Open Datasets to show how you can register and version a Dataset using the AML designer interface. In the first exercises we use a modified version of the original CSV file, which includes collected records for five months (January till May). The second exercise demonstrates how we can create a new version of the initial dataset when new data is collected (in this case, we included records collected in June in the CSV file).

**Download datasets:**<br>
https://introtomlsampledata.blob.core.windows.net/data/nyc-taxi/nyc-taxi-sample-data-5months.csv<br>
https://introtomlsampledata.blob.core.windows.net/data/nyc-taxi/nyc-taxi-sample-data-6months.csv

### Lab 3.15 Engineer and Select Features (Azure sample dataset): 

#### Summary:
This lab demonstrates the feature engineering process for building a regression model using bike rental demand prediction as an example. In machine learning predictions, effective feature engineering will lead to a more accurate model. We will use the Bike Rental UCI dataset as the input raw data for this experiment. This dataset is based on real data from the Capital Bikeshare company, which operates a bike rental network in Washington DC in the United States. The dataset contains 17,379 rows and 17 columns, each row representing the number of bike rentals within a specific hour of a day in the years 2011 or 2012. Weather conditions (such as temperature, humidity, and wind speed) were included in this raw feature set, and the dates were categorized as holiday vs. weekday etc.

The field to predict is cnt which contains a count value ranging from 1 to 977, representing the number of bike rentals within a specific hour. Our main goal is to construct effective features in the training data, so we build two models using the same algorithm, but with two different datasets. Using the Split Data module in the visual designer, we split the input data in such a way that the training data contains records for the year 2011, and the testing data, records for 2012. Both datasets have the same raw data at the origin, but we added different additional features to each training set:

* Set A = weather + holiday + weekday + weekend features for the predicted day
* Set B = number of bikes that were rented in each of the previous 12 hours

We are building two training datasets by combining the feature set as follows:
* Training set 1: feature set A only
* Training set 2: feature sets A+B

For the model, we are using regression because the number of rentals (the label column) contains continuous real numbers. As the algorithm for the experiment, we will be using the Boosted Decision Tree Regression.

**Download dataset:**
https://introtomlsampledata.blob.core.windows.net/data/bike-rental/bike-rental-hour.csv

### Python code used in lab 3.15:


```python
# The script MUST contain a function named azureml_main
# which is the entry point for this module.

# imports up here can be used to
import pandas as pd
import numpy as np

# The entry point function can contain up to two input arguments:
#   Param<dataframe1>: a pandas.DataFrame
#   Param<dataframe2>: a pandas.DataFrame
def azureml_main(dataframe1 = None, dataframe2 = None):

    # Execution logic goes here
    print(f'Input pandas.DataFrame #1: {dataframe1}')

    # If a zip file is connected to the third input port,
    # it is unzipped under "./Script Bundle". This directory is added
    # to sys.path. Therefore, if your zip file contains a Python file
    # mymodule.py you can import it using:
    # import mymodule

    for i in np.arange(1, 13):
        prev_col_name = 'cnt' if i == 1 else 'Rentals in hour -{}'.format(i-1)
        new_col_name = 'Rentals in hour -{}'.format(i)

        dataframe1[new_col_name] = dataframe1[prev_col_name].shift(1).fillna(0)

    # Return value must be of a sequence of pandas.DataFrame
    # E.g.
    #   -  Single return value: return dataframe1,
    #   -  Two return values: return dataframe1, dataframe2
    return dataframe1,
```

### Lab 3.27 Train and Evaluate a Model (Azure sample dataset): 

#### Summary:
In this lab, we will be using the Flight Delays data set that is enhanced with the weather data. Based on the enriched dataset, we will learn to use the Azure Machine Learning Graphical Interface to process data, build, train, score, and evaluate a classification model to predict if a particular flight will be delayed by 15 minutes or more. 

**Download dataset:**
https://introtomlsampledata.blob.core.windows.net/data/flightdelays/flightdelays.csv


### Lab 3.31 Train a Two-Class Boosted Decision Tree:

#### Summary:
In this lab, we will be using the Flight Delays data set that is enhanced with the weather data. Based on the enriched dataset, we will learn to use the Azure Machine Learning Graphical Interface to process data, build, train, score, and evaluate a classification model to predict if a particular flight will be delayed by 15 minutes or more. The classification algorithm used in this lab will be the ensemble algorithm: Two-Class Boosted Decision Tree. 

**Download dataset:**
https://introtomlsampledata.blob.core.windows.net/data/flightdelays/flightdelays.csv


### Lab 3.34 Train a Simple Classifier with Automated ML:

#### Summary:
In this lab, you learn how to create, run, and explore automated machine learning experiments in the Azure Machine Learning Studio without a single line of code. As part of this lab, we will be using the Flight Delays data set that is enhanced with the weather data. Based on the enriched dataset, we will use automated machine learning to find the best performing classification model to predict if a particular flight will be delayed by 15 minutes or more.

**Download dataset:**
 https://introtomlsampledata.blob.core.windows.net/data/flightdelays/flightdelays.csv


### Lab 4.4 Two-Class Classifiers Performance

#### Summary:
In this lab, we will be compare the performance of two binary classifiers: Two-Class Boosted Decision Tree and Two-Class Logistic Regression for predicting customer churn. The goal is to run an expensive marketing campaign for high risk customers; thus, the precision metric is going to be key in evaluating performance of these two algorithms. 

**Find dataset:**<br>
CRM dataset shared: https://docs.microsoft.com/en-us/azure/machine-learning/studio/use-sample-datasets


### Lab 4.8 Multi-Class Classifiers Performance:

#### Summary:
In this lab, we will be compare the performance of two different multiclass classification approaches: Two-Class Support Vector Machine used with One-vs-All Multiclass module vs Multiclass Decision Forest. We will apply the two approaches for the letter recognition problem and compare their performance. 

**Download dataset:**
https://www.kaggle.com/nishan192/letterrecognition-using-svm


### Lab 4.11 Training a Classifier Using Automated Machine Learning (Azure sample dataset):

#### Summary:
In this lab, we will use Automated Machine Learning to find the best performing binary classification model for predicting customer churn. We will do all of this from the Azure Machine Learning Studio without writing a single line of code.

**Download dataset:**
https://introtomlsampledata.blob.core.windows.net/data/crm-churn/crm-churn.csv


### Lab 4.15 Regressors Performance (Azure sample dataset):

#### Summary:
In this lab, we will be compare the performance of two regression algorithms: Boosted Decision Tree Regression and Neural Net Regression for predicting automobile prices. 

**Download dataset:**<br>
Automobile price data(raw): <br>
https://www.kaggle.com/toramky/automobile-dataset (.csv)

or

https://archive.ics.uci.edu/ml/datasets/Automobile (.data)


### Lab 4.19 Train a Regressor using Automated Machine Learning:

#### Summary:
In this lab, we will use Automated Machine Learning to find the best performing regression model for predicting automobile prices. 

**Download dataset:**
https://introtomlsampledata.blob.core.windows.net/data/automobile-price/automobile-price.csv


### Lab 4.25 Train a Simple Clustering Model (Azure sample dataset):

#### Summary:
In this lab, we will be using the Weather Dataset that has weather data for 66 different airports in the USA from April to October 2013. We will cluster the dataset into 5 distinct clusters based on key weather metrics, such as visibility, temperature, dew point, wind speed etc. The goal is to group airports with similar weather conditions. We will do all of this from the Azure Machine Learning designer without writing a single line of code.

**Download dataset:**
https://az754797.vo.msecnd.net/data/WeatherDataset.csv


### Lab 5.7 Train a Simple Neural Net:

#### Summary:
In this lab we will be using a subset of NYC Taxi & Limousine Commission - green taxi trip records available from Azure Open Datasets. The data is enriched with holiday and weather data. Based on the enriched dataset, we will configure the prebuilt Neural Network Regression module to create a regression model using a customizable neural network algorithm. We will train the model by providing the model and the NYC taxi dataset as an input to Train Model. The trained model can then be used to predict NYC taxi fares. 

**Download dataset:**
https://introtomlsampledata.blob.core.windows.net/data/nyc-taxi/nyc-taxi-sample-data.csv


### Lab 5.12 Train a Simple Recommender (Azure sample dataset):

#### Summary:
In this lab, we make use of the Train SVD Recommender module available in Azure Machine Learning designer (preview), to train a movie recommender engine. We use the collaborative filtering approach: the model learns from a collection of ratings made by users on a subset of a catalog of movies. Two open datasets available in Azure Machine Learning designer are used the IMDB Movie Titles dataset joined on the movie identifier with the Movie Ratings dataset. The Movie Ratings data consists of approximately 225,000 ratings for 15,742 movies by 26,770 users, extracted from Twitter using techniques described in the original paper by Dooms, De Pessemier and Martens. The paper and data can be found on GitHub.

We will both train the engine and score new data, to demonstrate the different modes in which a recommender can be used and evaluated. The trained model will predict what rating a user will give to unseen movies, so we’ll be able to recommend movies that the user is most likely to enjoy. 

**Find dataset:**
https://github.com/sidooms/MovieTweetings


### Lab 5.16 Train a Simple Text Classifier (Azure sample dataset):

#### Summary:
In this lab we demonstrate how to use text analytics modules available in Azure Machine Learning designer (preview) to build a simple text classification pipeline. We will create a training pipeline and initialize a multiclass logistic regression classifier to predict the company category with Wikipedia SP 500 dataset derived from Wikipedia. The dataset manages articles of each S&P 500 company. Before uploading to Azure Machine Learning designer, the dataset was processed as follows: extracted text content for each specific company, removed wiki formatting, removed non-alphanumeric characters, converted all text to lowercase, known company categories added. Articles could not be found for some companies, so that’s why the number of records is less than 500.

Data is derived from Wikipedia (https://www.wikipedia.org/) based on articles of each S&P 500 company, stored as XML data.

Before uploading to Azure Machine Learning Studio (classic), the dataset was processed as follows:
* 		Extract text content for each specific company
* 		Remove wiki formatting
* 		Remove non-alphanumeric characters
* 		Convert all text to lowercase
* 		Known company categories were added

Note that for some companies an article could not be found, so the number of records is less than 500.

**Find dataset:**
https://github.com/datasets/s-and-p-500-companies-financials
(WARNING: THIS MAY NOT BE THE ORIGINAL DATA USED IN AZURE LAB)


### Lab 5.23 Forecasting (Azure sample dataset):

#### Summary:
In this lab you will learn how the Automated Machine Learning capability in Azure Machine Learning (AML) can be used for the life cycle management of the manufactured vehicles and how AML helps in creation of better vehicle maintenance plans. To accomplish this, you will train a Linear Regression model to predict the number of days until battery failure using Automated Machine Learning available in AML studio.

**Download dataset:**
https://introtomlsampledata.blob.core.windows.net/data/battery-lifetime/training-formatted.csv


## Open Dataset Resources


### Azure sample datasets:
https://docs.microsoft.com/en-us/azure/machine-learning/studio/use-sample-datasets

### Azure open dataset:
https://azure.microsoft.com/en-us/services/open-datasets/catalog/

### UCI Machine Learning Repository:
https://archive.ics.uci.edu/ml/datasets.php

### 25 Excellent Machine Learning Open Datasets
https://medium.com/@ODSC/25-excellent-machine-learning-open-datasets-940ca2124dfc
