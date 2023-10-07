import { Component, OnInit } from '@angular/core';
import { FormArray, FormControl, FormGroup } from '@angular/forms';

@Component({
  selector: 'app-form-builder',
  templateUrl: './form-builder.component.html',
  styleUrls: ['./form-builder.component.css']
})
export class FormBuilderComponent implements OnInit{
  contactForm: FormGroup

  constructor(private fb: FormBuilder) {
    this.contactForm = this.fb.group();
  }

  ngOnInit(): void {
    throw new Error('Method not implemented.');
  }
}
