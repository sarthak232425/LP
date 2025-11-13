# Step 1: Import necessary libraries
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.naive_bayes import GaussianNB  # or use MultinomialNB for categorical data
from sklearn.metrics import accuracy_score, classification_report, confusion_matrix

# Step 2: Load the dataset
# Replace 'NaiveBayes.csv' with the actual path to your CSV file
data = pd.read_csv('NaiveBayes.csv')

# Step 3: Inspect the data (optional but useful)
print(data.head())  # View the first few rows of the dataset
print(data.info())  # Check for missing values or categorical features

# Step 4: Preprocess the data
# If necessary, handle missing values and encode categorical variables
# Assuming the target variable is the last column and the rest are features
X = data.iloc[:, :-1]  # Features (all columns except the target)
y = data.iloc[:, -1]   # Target variable (last column)

# Split the data into training and testing sets (80% training, 20% testing)
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Step 5: Train the Naïve Bayes Classifier
# Using Gaussian Naïve Bayes (use MultinomialNB for discrete features)
model = GaussianNB()
model.fit(X_train, y_train)

# Step 6: Make predictions
y_pred = model.predict(X_test)

# Step 7: Evaluate the performance of the model
# Accuracy
accuracy = accuracy_score(y_test, y_pred)
print(f"Accuracy: {accuracy:.4f}")

# Detailed classification report (precision, recall, f1-score)
print("\nClassification Report:")
print(classification_report(y_test, y_pred))

# Confusion Matrix
print("\nConfusion Matrix:")
print(confusion_matrix(y_test, y_pred))