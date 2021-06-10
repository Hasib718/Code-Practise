const todos = [];

while(true) {
    let input = prompt("What would you like to do").trim();
    
    if (input === "quit") break;

    switch(input) {
        case "new":
            input = prompt("Enter new todo");
            todos.push(input);
            console.log(`${input} added to list`);
            break;
        case "delete":
            input = parseInt(prompt("Enter index of todo to delete"));
            if (Number.isNaN(input) && input >= todos.length) {
                console.log("Invalid Index");
            } else {
                todos.splice(input, 1);
                console.log("Todo removed");
            }
            break;
        case "list":
            console.log("**********");
            for(let i=0; i<todos.length; i++) console.log(`${i}: ${todos[i]}`);
            console.log("**********");
            break;
        default:
            console.log("INVALID INPUT");
    }
}
console.log("OK, YOU QUIT THE APP");
