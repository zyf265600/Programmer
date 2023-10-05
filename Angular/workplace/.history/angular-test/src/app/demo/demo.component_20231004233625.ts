import { Component } from '@angular/core';
import { TestService } from '../test.service';

@Component({
  selector: 'app-demo',
  templateUrl: './demo.component.html',
  styleUrls: ['./demo.component.css']
})
export class DemoComponent {
  constructor(public testService:TestService) { }
}
