# Structuring-ML-Projects
_Tips on how to structure your machine learning project from deeplearning.ai_

## Assumptions in ML
#### 1. Fit Training set well on cost function - 
First, make sure that you're at least doing well on the training set. For some applications, this might mean doing comparably to human level performance. If your algorithm is not fitting the training set well on the cost function, then you might **train a bigger network** or switch to a **better optimization algorithm**, like the Adam optimization algorithm.

#### 2. Fit Dev set well on cost function - 
If your algorithm is not doing well on the dev set, **try regularization** or get a **bigger training set**.

#### 3. Fit Test set well on cost function - 
If it does well on the dev set but not the test set, it probably **means you've overtuned to your dev set**, and you need to go back and **find a bigger dev set**.

#### 4. Performs well in real world - 
If it does well on the test set, but it isn't delivering to you a happy cat picture app user, then what that means is that you want to go back and **change either the dev set** or the **cost function**. Because if doing well on the test set according to some cost function doesn't correspond to your algorithm doing what you need it to do in the real world, then it means that either **your dev test set distribution isn't set correctly**, or your **cost function isn't measuring the right thing**.

_When training a neural network, try not to use early stopping. It's not a bad technique, quite a lot of people do it. But early stopping difficult to think about. Because this is an op that simultaneously affects how well you fit the training set, because if you stop early, you fit the training set less well. It also simultaneously is often done to improve your dev set performance._ 

## Single number evaluation metric

This is used to improve your efficiency or the efficiency of your team in making those decisions. It tells you quickly if the new thing you just tried is working better or worse than your last idea

| Classifier | Precision | Recall| F1 score |
|----------|-----------|-------|----|
| A  | 95% | 90% | 92.4% |
| B | 98% | 85 | 91.0% |

The definition of **precision** is, of the examples that your classifier recognizes as cats, **What percentage actually are cats?** If classifier A has 95% precision, this means that when classifier A says something is a cat, there's a 95% chance it really is a cat.

And **recall** is, of all the images that really are cats, **what percentage were correctly recognized by your classifier?** So what percentage of actual cats, Are correctly recognized? So if classifier A is 90% recall, this means that of all of the images in, say, your dev sets that really are cats, classifier A pulled out 90% of them correctly.

There's often a tradeoff between precision and recall, and you care about both. The problem with using precision recall as your evaluation metric is that if classifier A does better on recall, which it does here, the classifier B does better on precision, then you're not sure which classifier is better. Therefore, pick a classifier, you just have to find a new evaluation metric that combines precision and recall. = **F1-score**

It is the average of precision, P, and recall, R. The F1 score is defined by this formula, it's **2 / (1/P + 1/R)**.

So what I found for a lot of machine learning teams is that **having a well-defined dev set**, which is **how you're measuring precision and recall**, plus a single number evaluation metric aka single row number evaluation metric allows you to quickly tell if classifier A or classifier B is better, and therefore having a dev set plus single number evaluation metric distance to speed up iterating. 

## Satisficing and Optimizing metric

Let's say that you've decided you care about the classification accuracy of your cat's classifier, this could have been F1 score or some other measure of accuracy, but let's say that in addition to accuracy you also care about the running time. So how long it takes to classify an image and classifier A takes 80 milliseconds, B takes 95 milliseconds, and C takes 1,500 milliseconds, that's 1.5 seconds to classify an image. So one thing you could do is combine accuracy and running time into an overall evaluation metric. And so the costs such as maybe the overall cost is accuracy minus 0.5 times running time.

| Classifier | Accuracy | Running Time | 
|----------|-----------|-------|
| A  | 90% | 80ms |
| B  | 92% | 95ms |
| C  | 95% | 1500ms |

So you could instead do is that you might want to choose a classifier that **maximizes accuracy** but subject to that the running time, that is the time it takes to classify an image, that that has to be **less than or equal to 100 milliseconds**. 
So in this case we would say that **accuracy is an optimizing metric** because you want to maximize accuracy. You want to do as well as possible on accuracy but that **running time is what we call a satisficing metric**. Meaning that it just has to be good enough, it just needs to be less than 100 milliseconds and beyond that you don't really care, or at least you don't care that much.
If the running time is less that 100 milliseconds, your users won't care that much whether it's 100 milliseconds or 50 milliseconds or even faster. And by defining optimizing as well as satisficing matrix, this gives you a clear way to pick the, best classifier, which in this case would be _classifier B_ because of all the ones with a running time better than 100 milliseconds it has the best accuracy.
So, if you have N matrix that you care about it's sometimes reasonable to pick one of them to be optimizing and do as well as is possible on that one. And then N-1 to be satisficing, meaning that so long as they reach some threshold such as running times faster than 100 milliseconds.

To summarize, **if there are multiple things you care about** by say there's one as the optimizing metric that you want to do as well as possible on and one or more as satisficing metrics where you'll be satisfice. Now these evaluation matrix must be evaluated or calculated on a training set or a development set or maybe on the test set. So one of the things you also need to do is set up training, dev or development, as well as test sets.

## Train/dev/test distributions

The way you set up your training dev, or development sets and test sets, can have a huge impact on how rapidly you or your team can make progress on building machine learning application.
So, that dev set is also called the development set, or sometimes called the hold out cross validation set. And, workflow in machine learning is that you try a lot of ideas, train up different models on the training set, and then use the dev set to evaluate the different ideas and pick one. And, keep innovating to improve dev set performance until, finally, you have one clause that you're happy with that you then evaluate on your test set. 

For example, you're building a cat crossfire, and you are operating in these regions:USA, UK, other European countries, South America, India, China, other Asian countries, and Australia. So, how do you set up your dev set and your test set? Well, one way you could do so is to pick first four of these regions into the dev set. And, the next four regions, will go into the test set. It turns out, this is _a very bad idea_ because in this example, your **dev and test sets come from different distributions**.

Another real life example I know is of a machine learning team that actually spent several months optimizing on a dev set which was comprised of loan approvals for medium income zip codes. So, the specific machine learning problem was, "Given an input X about a loan application, can you predict why and which is, whether or not, they'll repay the loan?" So, this helps you decide whether or not to approve a loan. And so, the dev set came from loan applications. They came from medium income zip codes. But, after working on this for a few months, the team then, suddenly decided to test this on data from low income zip codes or low income postal codes. And, of course, **the distributional data for medium income and low income zip codes is very different**. And, the crossfire, that they spend so much time optimizing in the former case, just didn't work well at all on the latter case.

So, to avoid this, what is recommended instead is that, you **randomly shuffle data** and separate it into the dev and test set. The dev and test sets will have the same distribution, which is the distribution of all of your data mixed together.

## Size of the dev and test sets

In machine learning, you usually 70/30 split data into a train and test set, or you would use a 60% training and 20% dev and 20% tests. In earlier eras of machine learning, this was pretty reasonable, especially back when data set sizes were just smaller like 1000 or 10,000. So if you had a hundred examples in total, these 70/30 or 60/20/20 rule of thumb would be pretty reasonable. 

But in the modern machine learning era, where we now work with much larger data set sizes(>1M). So let's say you have a million training examples, it might be quite reasonable to set up your data so that you have 98% in the training set, 1% dev, and 1% test. So, a 1% of that, is 10,000 examples, which might be enough for a dev set or for a test set. 






















