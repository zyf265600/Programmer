// import { fromEvent, from } from "rxjs"
// import { concatMap } from "rxjs/operators"
// import axios from "axios"

// const button = document.getElementById("btn")

// fromEvent(button, "click")
//   .pipe(
//     concatMap(event => from(axios.get("http://localhost:3005/token"))),
//     concatMap(token => from(axios.get("http://localhost:3005/userInfo")))
//   )
//   .subscribe(console.log)

import { Observable } from "rxjs"

const observable = new Observable(function (subscriber) {
  setTimeout(function () {
    observer.next({
      name: "张三"
    })
  }, 2000)
})

const observer = {
  next: function (value) {
    console.log(value)
  } 
}

observable.subscribe(observer)