import { Component, EventEmitter, Input } from '@angular/core';

@Component({
  selector: 'app-person',
  templateUrl: './person.component.html',
  styleUrls: ['./person.component.css']
})
export class PersonComponent {
  @Input("name") name: string = ""
  @Input("age") age: number = 0

  sendData = new EventEmitter<string>("The data");

  constructor() { }

  onClick() {
    console.log(this.name, this.age);
  }
}
