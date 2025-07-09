import streamlit as st
import pickle, re
from nltk.corpus import stopwords
from nltk.stem.porter import PorterStemmer

@st.cache(allow_output_mutation=True)
def load_artifacts():
    with open("cv.pkl", "rb") as f:
        cv = pickle.load(f)
    with open("LR.pkl", "rb") as f:
        model_lr = pickle.load(f)
    with open("DTC.pkl", "rb") as f:
        model_dt = pickle.load(f)
    with open("MNB.pkl", "rb") as f:
        model_nb = pickle.load(f)
    return cv, model_lr, model_dt, model_nb

cv, model_lr, model_dt, model_nb = load_artifacts()
ps = PorterStemmer()
stop_words = set(stopwords.words('english'))

def preprocess(text):
    tokens = re.sub('[^a-zA-Z]', ' ', text).lower().split()
    return ' '.join(ps.stem(w) for w in tokens if w not in stop_words)

def predict(text, model):
    vector = cv.transform([preprocess(text)]).toarray()
    return model.predict(vector)[0]

st.title("📧 Spam Detector")
user_input = st.text_area("Enter email text")
model_choice = st.selectbox("Model", ["Logistic Regression","Decision Tree","Multinomial NB"])

if st.button("Predict"):
    if not user_input.strip():
        st.warning("Enter some text first!")
    else:
        mapping = {
            "Logistic Regression": model_lr,
            "Decision Tree":       model_dt,
            "Multinomial NB":      model_nb
        }
        pred = predict(user_input, mapping[model_choice])
        st.success("🛑 SPAM" if pred==1 else "✅ HAM")
