import { Component, OnInit } from '@angular/core';
import { FormArray, FormBuilder, FormControl, FormGroup, Validators } from '@angular/forms';

interface Data {
  name: string,
  value: string
}

@Component({
  selector: 'app-form-checkbox',
  templateUrl: './form-checkbox.component.html',
  styleUrls: ['./form-checkbox.component.css']
})
export class FormCheckboxComponent {
  Data: Array<Data> = [
    { name: "Pear", value: "pear" },
    { name: "Plum", value: "plum" },
    { name: "Kiwi", value: "kiwi" },
    { name: "Apple", value: "apple" },
    { name: "Lime", value: "lime" }
  ]

  form: FormGroup

  constructor(private fb: FormBuilder) {
    this.form = this.fb.group({
      checkArray: this.fb.array([])
    })
  }

  onSubmit() {

  }

  onChange(event: Event) {
    const target = event.target as HTMLInputElement;
    const value = target.value;
    const checked = target.checked;
    const checkArray = this.form.get("checkArray") as FormArray;
    if (checked) {
      checkArray.push(this.fb.control(value));
    } else {
      const index = checkArray.controls.findIndex(control => control.value === value);
      checkArray.removeAt(index);
    }
    console.log(checkArray.value)
  }
}
