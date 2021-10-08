import React, {useState} from 'react';

const questions = [
    {
        questionText: 'MERN stack refers to ______',
        answerOptions: [
            {answerText: 'MySQL, Emmet, React, Node', isCorrect: false},
            {answerText: 'MySQL, Express JS, React, NPM', isCorrect: false},
            {answerText: 'MongoDB, Express JS, React, Node', isCorrect: true},
            {answerText: 'MongoDB, Emmet, React, NPM', isCorrect: false},
        ],
    },
    {
        questionText: 'Which one of these is a package manager for Node?',
        answerOptions: [
            {answerText: 'Pip', isCorrect: false},
            {answerText: 'Conda', isCorrect: false},
            {answerText: 'NPM', isCorrect: true},
            {answerText: 'Homebrew', isCorrect: false},
        ],
    },
    {
        questionText: 'Which of these languages compiles directly to JavaScript?',
        answerOptions: [
            {answerText: 'Java', isCorrect: false},
            {answerText: 'CoffeeScript', isCorrect: true},
            {answerText: 'Perl', isCorrect: false},
            {answerText: 'Python', isCorrect: false},
        ],
    },
    {
        questionText: 'Angular is developed by _______',
        answerOptions: [
            {answerText: 'Google', isCorrect: true},
            {answerText: 'FaceBook', isCorrect: false},
            {answerText: 'Amazon', isCorrect: false},
            {answerText: 'Microsoft', isCorrect: false},
        ],
    },
    {
        questionText: 'Which one of these is NOT a JS framework?',
        answerOptions: [
            {answerText: 'Svelte', isCorrect: false},
            {answerText: 'Vue', isCorrect: false},
            {answerText: 'Next', isCorrect: false},
            {answerText: 'Django', isCorrect: true},
        ],
    },
];

export default function App(props) {
    const [currentQuestion, setCurrentQuestion] = useState(0);
    const [showScore, setShowScore] = useState(false);
    const [score, setScore] = useState(0);

    const handleAnswerOptionClick = (isCorrect) => {
        if (isCorrect) {
            setScore(score + 1);
        }

        const nextQuestion = currentQuestion + 1;
        if (nextQuestion < questions.length) {
            setCurrentQuestion(nextQuestion);
        } else {
            setShowScore(true);
        }
    };
    return (
        <div className='app'>
            {showScore ? (
                <div className='score-section'>
                    You scored {score} out of {questions.length}!
                </div>
            ) : (
                <>
                    <div className='question-section'>
                        <div className='question-count'>
                            <span>Question {currentQuestion + 1}</span>
                        </div>
                        <div className='question-text'>{questions[currentQuestion].questionText}</div>
                    </div>
                    <div className='answer-section'>
                        {questions[currentQuestion].answerOptions.map((answerOption) => (
                            <button onClick={() => handleAnswerOptionClick(answerOption.isCorrect)}>
                                {answerOption.answerText}
                            </button>
                        ))}
                    </div>
                </>
            )}
        </div>
    );
}
