import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error, r2_score
from sklearn.preprocessing import LabelEncoder, StandardScaler

# Load the dataset
data = pd.read_csv('advertising.csv')

# Display basic info to check for categorical data or scaling needs
print(data.info())
print(data.describe())

# Assume 'TV' as the advertising spending feature and 'Sales' as the target variable
X = data[['TV']]      # Feature: TV advertising spending
y = data['Sales']     # Target: Sales

# Split dataset into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Initialize and train the regression model
model = LinearRegression()
model.fit(X_train, y_train)

# Make predictions on the test set
y_pred = model.predict(X_test)

# Calculate metrics
coefficients = model.coef_
intercept = model.intercept_
rss = np.sum((y_test - y_pred) ** 2)
r2 = r2_score(y_test, y_pred)

# Display results
print(f'Coefficients: {coefficients}')
print(f'Intercept: {intercept}')
print(f'Residual Sum of Squares (RSS): {rss}')
print(f'Coefficient of Determination (R^2): {r2}')

# Plotting the regression line
plt.figure(figsize=(10, 6))
plt.scatter(X_test, y_test, color='blue', label='Actual Sales')
plt.plot(X_test, y_pred, color='red', linewidth=2, label='Regression Line')
plt.xlabel('TV Advertising Spending')
plt.ylabel('Sales')
plt.title('Linear Regression: TV Advertising Spending vs Sales')
plt.legend()
plt.show()