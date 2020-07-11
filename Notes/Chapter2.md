
# Chapter 2 - Introduction to Machine Learning
---

## Scaling Data

### Standardization

Standardization rescales data so that it has a mean of 0 and a standard deviation of 1.
The formula for this is:

> (𝑥 − 𝜇)/𝜎

### Normalization

Normalization rescales the data into the range [0, 1].
The formula for this is:

> (𝑥 −𝑥𝑚𝑖𝑛)/(𝑥𝑚𝑎𝑥 −𝑥𝑚𝑖𝑛)

---

## Encoding

### Ordinal Encoding

In ordinal encoding, we simply convert the categorical data into integer codes ranging from 0 to (number of categories – 1)

### One-Hot Encoding

One-hot encoding is a very different approach. In one-hot encoding, we transform each categorical value into a column. If there are n categorical values, n new columns are added. For example, the Color property has three categorical values: Red, Green, and Blue, so three new columns Red, Green, and Blue are added.

---

## Text Data

In summary, a typical pipeline for text data begins by pre-processing or normalizing the text. This step typically includes tasks such as breaking the text into sentence and word tokens, standardizing the spelling of words, and removing overly common words (called stop words).
The next step is feature extraction and vectorization, which creates a numeric representation of the documents. Common approaches include TF-IDF vectorization, Word2vec, and Global Vectors (GloVe).

Last, we will feed the vectorized document and labels into a model and start the training.

---

## ML Perspective

### Computer 
We are using input features to create a program that can generate the desired output.

### Statistics 
We are trying to find a mathematical function that, given the values of the independent variables can predict the values of the dependent variables.

---

## Data Terminology

For the rows in the table, we might call each row an entity or an observation about an entity. In our example above, each entity is simply a product, and when we speak of an observation, we are simply referring to the data collected about a given product. You'll also sometimes see a row of data referred to as an instance, in the sense that a row may be considered a single example (or instance) of data.

For the columns in the table, we might refer to each column as a feature or attribute which describes the property of an entity. In the above example, color and quantity are features (or attributes) of the products.