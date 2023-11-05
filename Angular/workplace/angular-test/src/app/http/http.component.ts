import { Component, OnInit } from '@angular/core';
import { HttpClient, HttpHeaders, HttpParams } from "@angular/common/http"
import { from } from 'rxjs';


@Component({
  selector: 'app-http',
  templateUrl: './http.component.html',
  styleUrls: ['./http.component.css']
})
export class HttpComponent implements OnInit {
  constructor(private http: HttpClient) { }

  ngOnInit() {
    let params = new HttpParams({ fromString: "name=yoma&age=22" })

    let headers = new HttpHeaders({ test: "Hello" })

    this.http.get("https://jsonplaceholder.typicode.com/users", {params, headers, observe: "response"}).subscribe(console.log)
    // this.http.get("http://localhost:8080/simpleParam", {params}).subscribe(console.log)

  }
}
